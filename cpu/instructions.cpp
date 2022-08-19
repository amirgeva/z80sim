#include <stdexcept>
#include <string>
#include <assert.h>
#include "z80.h"
#include "consts.h"
#include "utils.h"

#pragma warning (disable : 4244)

#define NOT_IMPLEMENTED throw std::runtime_error("Not implemented")
#define REGISTER(x) m_Refs[#x] = std::make_shared<BasicAccessor<byte>>(&m_Registers.x)
#define REGISTER16(x) m_Refs[#x] = std::make_shared<BasicAccessor<word>>(&m_Registers.x)
#define SPECIAL(x) m_Refs[#x] = std::make_shared<BasicAccessor<byte>>(&m_Special.x)
#define SPECIAL16(x) m_Refs[#x] = std::make_shared<BasicAccessor<word>>(&m_Special.x)
#define REF(x) m_Refs[#x]
#define FLAG(x) m_Flags[#x]
#define CFLAG(x) m_CPU->m_Flags[#x]
#define REPEAT m_CPU->repeat(size())
#define USING(REG) auto& REG = m_CPU->m_Registers.REG
#define USING_SPECIAL(REG) auto& REG = m_CPU->m_Special.REG

namespace z80sim
{
	word SignExtend(byte b)
	{
		if ((b & 0x80) == 0) return b;
		return 0xFF00 | b;
	}


#define INSTRUCTION(name) class Instruction_##name;\
class Instruction_##name : public Instruction {\
	CPU*						m_CPU;\
	std::vector<accessor_ptr>	m_Operands;\
public:\
	Instruction_##name(CPU* cpu, byte size, const std::vector<accessor_ptr>& operands)\
	: Instruction(size)\
	, m_CPU(cpu)\
	, m_Operands(operands) {}\
	virtual void execute() override;\
	static instruction_ptr create(CPU* cpu, byte size, const std::vector<accessor_ptr>& operands)\
	{ return std::make_shared<Instruction_##name>(cpu,size,operands); }\
};\
void Instruction_##name::execute()

#define UNARY_ALU_OP(x) assert(m_Operands.size() == 1); \
if (m_Operands[0]->is_word())\
  m_Operands[0]->write(m_CPU->alu.W_##x(m_Operands[0]->read()));\
else\
  m_Operands[0]->write(m_CPU->alu.x(m_Operands[0]->read()));

#define BINARY_ALU_OP(x) assert(m_Operands.size()==2);\
if (m_Operands[0]->is_word())\
  m_Operands[0]->write(m_CPU->alu.W_##x(m_Operands[0]->read(), m_Operands[1]->read()));\
else\
  m_Operands[0]->write(m_CPU->alu.x(m_Operands[0]->read(), m_Operands[1]->read()));

#define BINARY_ALU_INSTRUCTION(x) INSTRUCTION(x) { BINARY_ALU_OP(x); }

	BINARY_ALU_INSTRUCTION(ADC)
	BINARY_ALU_INSTRUCTION(ADD)
	BINARY_ALU_INSTRUCTION(SUB)
	BINARY_ALU_INSTRUCTION(SBC)
	BINARY_ALU_INSTRUCTION(AND)
	BINARY_ALU_INSTRUCTION(OR)
	BINARY_ALU_INSTRUCTION(XOR)
	//BINARY_ALU_INSTRUCTION(CP)
	
	INSTRUCTION(INC) { UNARY_ALU_OP(INC); }
	INSTRUCTION(DEC) { UNARY_ALU_OP(DEC); }

	INSTRUCTION(BIT)
	{
		byte bit = m_Operands[0]->read();
		byte data = m_Operands[1]->read();
		byte z = (data & (1 << bit)) == 0 ? FZ : 0;
		m_CPU->assign_flags(FH | FN | FZ, FH | z);
	}

	INSTRUCTION(CALL)
	{
		assert(m_Operands.size() <= 2);
		accessor_ptr a = m_Operands[0];
		if (m_Operands.size() > 1)
		{
			if (a->read() == 0) return;
			a = m_Operands[1];
		}
		USING_SPECIAL(PC);
		m_CPU->push(PC+size());
		PC = a->read() - size();
	}

	INSTRUCTION(CCF)
	{
		m_CPU->reset_flags(FC);
	}

	INSTRUCTION(SCF)
	{
		m_CPU->set_flags(FC);
	}

	INSTRUCTION(CP)
	{
		m_CPU->alu.SUB(m_Operands[0]->read(), m_Operands[1]->read());
	}

	INSTRUCTION(CPD)
	{
		USING(A);
		USING(HL);
		USING(BC);
		byte c_state = m_CPU->m_Registers.F & FC;
		m_CPU->alu.SUB(A, m_CPU->read_byte(HL));
		HL--;
		BC--;
		m_CPU->assign_flags(FC | FN | FPV, c_state | FN | (BC != 0 ? FPV : 0));
	}

	INSTRUCTION(CPDR)
	{
		USING(A);
		USING(HL);
		USING(BC);
		byte c_state = m_CPU->m_Registers.F & FC;
		byte res = 0;
		do
		{
			res = m_CPU->alu.SUB(A, m_CPU->read_byte(HL));
			HL--;
			BC--;
		} while (BC != 0 && res != 0);
		m_CPU->assign_flags(FC | FN | FPV, c_state | FN | (BC != 0 ? FPV : 0));
	}

	INSTRUCTION(CPI)
	{
		USING(A);
		USING(HL);
		USING(BC);
		byte c_state = m_CPU->m_Registers.F & FC;
		m_CPU->alu.SUB(A, m_CPU->read_byte(HL));
		HL++;
		BC--;
		m_CPU->assign_flags(FC | FN | FPV, c_state | FN | (BC != 0 ? FPV : 0));
	}

	INSTRUCTION(CPIR)
	{
		USING(A);
		USING(HL);
		USING(BC);
		byte c_state = m_CPU->m_Registers.F & FC;
		byte res = 0;
		do
		{
			res = m_CPU->alu.SUB(A, m_CPU->read_byte(HL));
			HL++;
			BC--;
		} while (BC != 0 && res != 0);
		m_CPU->assign_flags(FC | FN | FPV, c_state | FN | (BC != 0 ? FPV : 0));
	}

	INSTRUCTION(CPL)
	{
		USING(A);
		A = ~A;
		m_CPU->set_flags(FH | FN);
	}

	INSTRUCTION(DAA)
	{
		NOT_IMPLEMENTED;
	}

	INSTRUCTION(DI)
	{
		m_CPU->interrupts(false);
	}

	INSTRUCTION(EI)
	{
		m_CPU->interrupts(true);
	}

	INSTRUCTION(DJNZ)
	{
		USING(B);
		USING_SPECIAL(PC);
		if (--B != 0)
			PC += SignExtend(m_Operands[0]->read());
	}

	INSTRUCTION(EX)
	{
		auto a = m_Operands[0]->read();
		m_Operands[0]->write(m_Operands[1]->read());
		m_Operands[1]->write(a);
	}

	INSTRUCTION(EXX)
	{
		m_CPU->exx();
	}

	INSTRUCTION(HALT)
	{
		NOT_IMPLEMENTED;
	}

	INSTRUCTION(IM)
	{
		m_CPU->set_interrupt_mode(m_Operands[0]->read());
	}

	INSTRUCTION(IN)
	{
		byte a = m_CPU->input(m_Operands[1]->read());
		m_Operands[0]->write(a);
		if (!m_Operands[1]->is_literal())
			m_CPU->assign_flags(FS | FZ | FH | FPV | FN, (a & 0x80 ? FS : 0) | (a == 0 ? FZ : 0) | (even(a) ? FPV : 0));
	}

	INSTRUCTION(INI)
	{
		byte c_state = m_CPU->m_Registers.F & FC;
		USING(B);
		USING(C);
		USING(HL);
		m_CPU->write_byte(HL, m_CPU->input(C));
		B = m_CPU->alu.SUB(B, 1);
		HL++;
		m_CPU->assign_flags(FN | FC | FZ, FN | c_state | (B==0?FZ:0));
	}

	INSTRUCTION(INIR)
	{
		byte c_state = m_CPU->m_Registers.F & FC;
		USING(B);
		USING(C);
		USING(HL);
		do
		{
			m_CPU->write_byte(HL, m_CPU->input(C));
			B = m_CPU->alu.SUB(B, 1);
			HL++;
		} while (B != 0);
		m_CPU->assign_flags(FN | FC | FZ, FN | c_state | FZ);
	}

	INSTRUCTION(IND)
	{
		byte c_state = m_CPU->m_Registers.F & FC;
		USING(B);
		USING(C);
		USING(HL);
		m_CPU->write_byte(HL, m_CPU->input(C));
		B = m_CPU->alu.SUB(B, 1);
		HL--;
		m_CPU->assign_flags(FN | FC | FZ, FN | c_state | (B == 0 ? FZ : 0));
	}

	INSTRUCTION(INDR)
	{
		byte c_state = m_CPU->m_Registers.F & FC;
		USING(B);
		USING(C);
		USING(HL);
		do
		{
			m_CPU->write_byte(HL, m_CPU->input(C));
			B = m_CPU->alu.SUB(B, 1);
			HL--;
		} while (B != 0);
		m_CPU->assign_flags(FN | FC | FZ, FN | c_state | FZ);
	}

	INSTRUCTION(JP)
	{
		assert(m_Operands.size() <= 2);
		accessor_ptr a = m_Operands[0];
		if (m_Operands.size() > 1)
		{
			if (a->read() == 0) return;
			a = m_Operands[1];
		}
		USING_SPECIAL(PC);
		PC = a->read() - size();
	}

	INSTRUCTION(JR)
	{
		assert(m_Operands.size() <= 2);
		accessor_ptr a = m_Operands[0];
		if (m_Operands.size() > 1)
		{
			if (a->read() == 0) return;
			a = m_Operands[1];
		}
		USING_SPECIAL(PC);
		PC += SignExtend(a->read());
	}

	INSTRUCTION(LD)
	{
		assert(m_Operands.size() == 2);
		m_Operands[0]->write(m_Operands[1]->read());
	}

	INSTRUCTION(LDD)
	{
		USING(BC);
		USING(DE);
		USING(HL);
		m_CPU->copy_ram(HL, DE);
		DE--;
		HL--;
		BC--;
		m_CPU->reset_flags(FH | FN | (BC?FPV:0));
	}

	INSTRUCTION(LDDR)
	{
		USING(BC);
		USING(DE);
		USING(HL);
		m_CPU->copy_ram(HL, DE);
		DE--;
		HL--;
		BC--;
		m_CPU->reset_flags(FH | FN | FPV);
		if (BC) REPEAT;
	}

	INSTRUCTION(LDI)
	{
		USING(BC);
		USING(DE);
		USING(HL);
		m_CPU->copy_ram(HL, DE);
		DE++;
		HL++;
		BC--;
		m_CPU->reset_flags(FH | FN | (BC ? FPV : 0));
	}

	INSTRUCTION(LDIR)
	{
		USING(BC);
		USING(DE);
		USING(HL);
		m_CPU->copy_ram(HL, DE);
		DE++;
		HL++;
		BC--;
		m_CPU->reset_flags(FH | FN | FPV);
		if (BC) REPEAT;
	}

	INSTRUCTION(NEG)
	{
		USING(A);
		byte set_flags = FN | (A == 0x80 ? FPV : 0) | (A == 0 ? FC : 0);
		byte reset_flags = (A == 0x80 ? 0 : FPV) | (A == 0 ? 0 : FC);
		A = m_CPU->alu.SUB(0, A);
		m_CPU->reset_flags(reset_flags);
		m_CPU->set_flags(set_flags);
	}

	INSTRUCTION(NOP)
	{}

	INSTRUCTION(OUT)
	{
		m_CPU->output(m_Operands[0]->read(), m_Operands[1]->read());
	}

	INSTRUCTION(OUTI)
	{
		USING(B);
		USING(C);
		USING(HL);
		byte c_state = (m_CPU->m_Registers.F & FC);
		m_CPU->output(C, m_CPU->read_byte(HL));
		B--;
		HL++;
		m_CPU->assign_flags(FN | FC | FZ, c_state | FN | ((B == 0) ? FZ : 0));
	}

	INSTRUCTION(OTIR)
	{
		USING(B);
		USING(C);
		USING(HL);
		byte c_state = (m_CPU->m_Registers.F & FC);
		do
		{
			m_CPU->output(C, m_CPU->read_byte(HL));
			B--;
			HL++;
		} while (B != 0);
		m_CPU->assign_flags(FN | FC | FZ, c_state | FN | FZ);
	}

	INSTRUCTION(OUTD)
	{
		USING(B);
		USING(C);
		USING(HL);
		byte c_state = (m_CPU->m_Registers.F & FC);
		m_CPU->output(C, m_CPU->read_byte(HL));
		B--;
		HL--;
		m_CPU->assign_flags(FN | FC | FZ, c_state | FN | ((B == 0) ? FZ : 0));
	}

	INSTRUCTION(OTDR)
	{
		USING(B);
		USING(C);
		USING(HL);
		byte c_state = (m_CPU->m_Registers.F & FC);
		do
		{
			m_CPU->output(C, m_CPU->read_byte(HL));
			B--;
			HL--;
		} while (B != 0);
		m_CPU->assign_flags(FN | FC | FZ, c_state | FN | FZ);
	}

	INSTRUCTION(PUSH)
	{
		m_CPU->push(m_Operands[0]->read());
	}

	INSTRUCTION(POP)
	{
		USING_SPECIAL(SP);
		m_Operands[0]->write(m_CPU->read_word(SP));
		SP += 2;
	}

	INSTRUCTION(RES)
	{
		byte mask = (1 << m_Operands[0]->read());
		byte data = m_Operands[1]->read();
		m_Operands[1]->write(data & ~mask);
	}

	INSTRUCTION(SET)
	{
		byte mask = (1 << m_Operands[0]->read());
		byte data = m_Operands[1]->read();
		m_Operands[1]->write(data | mask);
	}

	INSTRUCTION(RET)
	{
		USING_SPECIAL(PC);
		USING_SPECIAL(SP);
		if (!m_Operands.empty())
		{
			if (m_Operands[0]->read() == 0) return;
		}
		PC = m_CPU->read_word(SP) - size();
		SP += 2;
	}

	INSTRUCTION(RETI)
	{
		USING_SPECIAL(PC);
		USING_SPECIAL(SP);
		PC = m_CPU->read_word(SP) - size();
		SP += 2;
	}

	INSTRUCTION(RETN)
	{
		USING_SPECIAL(PC);
		USING_SPECIAL(SP);
		PC = m_CPU->read_word(SP) - size();
		SP += 2;
	}

	INSTRUCTION(RST)
	{
		USING_SPECIAL(PC);
		USING_SPECIAL(SP);
		m_CPU->push(PC+size());
		PC = (m_Operands[0]->read() << 3) - size();
	}

	INSTRUCTION(RLCA)
	{
		USING(A);
		A = m_CPU->alu.RLC(A);
	}

	INSTRUCTION(RLA)
	{
		USING(A);
		A = m_CPU->alu.RLA(A);
	}

	INSTRUCTION(RRCA)
	{
		USING(A);
		A = m_CPU->alu.RRC(A);
	}

	INSTRUCTION(RRA)
	{
		USING(A);
		A = m_CPU->alu.RRA(A);
	}

	INSTRUCTION(RLC)
	{
		m_Operands[0]->write(m_CPU->alu.RLC(m_Operands[0]->read()));
	}

	INSTRUCTION(RL)
	{
		m_Operands[0]->write(m_CPU->alu.RLA(m_Operands[0]->read()));
	}

	INSTRUCTION(RRC)
	{
		m_Operands[0]->write(m_CPU->alu.RRC(m_Operands[0]->read()));
	}

	INSTRUCTION(RR)
	{
		m_Operands[0]->write(m_CPU->alu.RRA(m_Operands[0]->read()));
	}

	INSTRUCTION(SLA)
	{
		m_Operands[0]->write(m_CPU->alu.SLA(m_Operands[0]->read()));
	}

	INSTRUCTION(SRA)
	{
		m_Operands[0]->write(m_CPU->alu.SRA(m_Operands[0]->read()));
	}

	INSTRUCTION(SRL)
	{
		m_Operands[0]->write(m_CPU->alu.SRL(m_Operands[0]->read()));
	}

	INSTRUCTION(RLD)
	{
		USING(A);
		USING(HL);
		byte l = A & 0x0F;
		byte b=m_CPU->read_byte(HL);
		A = (A & 0xF0) | (b >> 4);
		b = (b << 4) | l;
		m_CPU->write_byte(HL, b);
		m_CPU->assign_flags(FS | FZ | FH | FPV | FN, (A & 0x80 ? FS : 0) | (A == 0 ? FZ : 0) | (even(A) ? FPV : 0));
	}

	INSTRUCTION(RRD)
	{
		USING(A);
		USING(HL);
		byte l = A & 0x0F;
		byte b = m_CPU->read_byte(HL);
		A = (A & 0xF0) | (b & 0x0F);
		b = (l << 4) | (b >> 4);
		m_CPU->write_byte(HL, b);
		m_CPU->assign_flags(FS | FZ | FH | FPV | FN, (A & 0x80 ? FS : 0) | (A == 0 ? FZ : 0) | (even(A) ? FPV : 0));
	}

	void CPU::setup_references()
	{
		REGISTER(F);
		REGISTER(A);
		REGISTER(B);
		REGISTER(C);
		REGISTER(D);
		REGISTER(E);
		REGISTER(H);
		REGISTER(L);
		REGISTER16(AF);
		REGISTER16(BC);
		REGISTER16(DE);
		REGISTER16(HL);
		SPECIAL(R);
		SPECIAL(I);
		SPECIAL16(PC);
		SPECIAL16(SP);
		SPECIAL16(IX);
		SPECIAL16(IY);
		m_Refs["AFt"] = std::make_shared<BasicAccessor<word>>(&m_AltRegisters.AF);
		m_Refs["(C)"] = std::make_shared<BasicAccessor<byte>>(&m_Registers.C);
		m_Flags["C"] = std::make_shared<FlagAccessor>(&m_Registers.F, 0, false);
		m_Flags["NC"] = std::make_shared<FlagAccessor>(&m_Registers.F, 0, true);
		m_Flags["Z"] = std::make_shared<FlagAccessor>(&m_Registers.F, 6, false);
		m_Flags["NZ"] = std::make_shared<FlagAccessor>(&m_Registers.F, 6, true);
		m_Flags["M"] = std::make_shared<FlagAccessor>(&m_Registers.F, 7, false);
		m_Flags["S"] = std::make_shared<FlagAccessor>(&m_Registers.F, 7, false);
		m_Flags["P"] = std::make_shared<FlagAccessor>(&m_Registers.F, 7, true);
		m_Flags["PE"] = std::make_shared<FlagAccessor>(&m_Registers.F, 2, false);
		m_Flags["P/V"] = std::make_shared<FlagAccessor>(&m_Registers.F, 2, false);
		m_Flags["PO"] = std::make_shared<FlagAccessor>(&m_Registers.F, 2, true);
		m_Flags["N"] = std::make_shared<FlagAccessor>(&m_Registers.F, 1, false);
		m_Flags["H"] = std::make_shared<FlagAccessor>(&m_Registers.F, 4, false);

		m_Refs["PC8_1"] = std::make_shared<IndirectAccessor>(this, REF(PC), 1);
		m_Refs["PC8_2"] = std::make_shared<IndirectAccessor>(this, REF(PC), 2);
		m_Refs["PC8_3"] = std::make_shared<IndirectAccessor>(this, REF(PC), 3);
		m_Refs["SPC8_1"] = Signed(std::make_shared<IndirectAccessor>(this, REF(PC), 1));
		m_Refs["SPC8_2"] = Signed(std::make_shared<IndirectAccessor>(this, REF(PC), 2));
		m_Refs["SPC8_3"] = Signed(std::make_shared<IndirectAccessor>(this, REF(PC), 3));
		m_Refs["PC16_1"] = std::make_shared<IndirectAccessorW>(this, REF(PC), 1);
		m_Refs["PC16_2"] = std::make_shared<IndirectAccessorW>(this, REF(PC), 2);
		
		{
			// Double indirections
			auto ptr = std::make_shared<IndirectAccessorW>(this, REF(PC), 1);
			m_Refs["BPC16_1"] = std::make_shared<IndirectAccessor>(this, ptr, 0);
			m_Refs["WPC16_1"] = std::make_shared<IndirectAccessorW>(this, ptr, 0);
			ptr = std::make_shared<IndirectAccessorW>(this, REF(PC), 2);
			m_Refs["WPC16_2"] = std::make_shared<IndirectAccessorW>(this, ptr, 0);
		}
		m_Refs["(IX+::)"] = std::make_shared<IndirectAccessor>(this, REF(IX), Signed(REF(PC8_2)));
		m_Refs["(IY+::)"] = std::make_shared<IndirectAccessor>(this, REF(IY), Signed(REF(PC8_2)));
		m_Refs["(BC)"] = std::make_shared<IndirectAccessor>(this, REF(BC), 0);
		m_Refs["(DE)"] = std::make_shared<IndirectAccessor>(this, REF(DE), 0);
		m_Refs["(HL)"] = std::make_shared<IndirectAccessor>(this, REF(HL), 0);
		m_Refs["(SP)"] = std::make_shared<IndirectAccessor>(this, REF(SP), 0);
		m_Refs["W(SP)"] = std::make_shared<IndirectAccessorW>(this, REF(SP), 0);
		m_Refs["(IX)"] = std::make_shared<IndirectAccessor>(this, REF(IX), 0);
		m_Refs["(IY)"] = std::make_shared<IndirectAccessor>(this, REF(IY), 0);
		m_Refs["W(HL)"] = std::make_shared<IndirectAccessorW>(this, REF(HL), 0);
		m_Refs["W(IX)"] = std::make_shared<IndirectAccessorW>(this, REF(IX), 0);
		m_Refs["W(IY)"] = std::make_shared<IndirectAccessorW>(this, REF(IY), 0);
		for (word value = 0; value < 256; ++value)
			m_Refs[std::to_string(value)] = std::make_shared<LiteralAccessor>(value);
	}

	void CPU::setup_instructions()
	{
#include "instructions.inl"
	}


} // namespace z80sim
