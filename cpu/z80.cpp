#include <stdexcept>
#include <cassert>
#include <algorithm>
#include "z80.h"
#include "consts.h"
#include "utils.h"

namespace z80sim
{
	ALU::ALU(CPU* cpu)
		: m_CPU(cpu)
	{}

	byte ALU::ADD(byte a, byte b)
	{
		bool pa = (a & 0x80) == 0;
		bool pb = (b & 0x80) == 0;
		word w = word(a) + word(b);
		bool pw = (w & 0x80) == 0;
		byte o = (pa == pb && pa != pw) ? 1 : 0;
		byte r = byte(w);
		byte c = (w > 0xFF) ? 1 : 0;
		byte h = ((a & 0x0F) + (b & 0x0F)) > 0x0F ? 1 : 0;
		m_CPU->assign_alu_flags(r, c, h, o);
		return r;
	}
	
	byte ALU::ADC(byte a, byte b)
	{
		bool pa = (a & 0x80) == 0;
		bool pb = (b & 0x80) == 0;
		byte c = (m_CPU->m_Registers.F & FC) ? 1 : 0;
		word w = word(a) + word(b) + word(c);
		bool pw = (w & 0x80) == 0;
		byte o = (pa == pb && pa != pw) ? 1 : 0;
		byte r = byte(w);
		byte h = ((a & 0x0F) + (b & 0x0F) + c) > 0x0F ? 1 : 0;
		c = (w > 0xFF) ? 1 : 0;
		m_CPU->assign_alu_flags(r, c, h, o);
		return r;
	}

	byte ALU::SUB(byte a, byte b)
	{
		bool pa = (a & 0x80) == 0;
		bool pb = (b & 0x80) == 0;
		word w = word(a) - word(b);
		bool pw = (w & 0x80) == 0;
		byte o = (pa != pb && pa != pw) ? 1 : 0;
		byte r = byte(w);
		byte h = ((a & 0x0F) - (b & 0x0F)) > 0x0F ? 1 : 0;
		byte c = (w > 0xFF) ? 1 : 0;
		m_CPU->assign_alu_flags(r, c, h, o);
		return r;
	}

	byte ALU::SBC(byte a, byte b)
	{
		bool pa = (a & 0x80) == 0;
		bool pb = (b & 0x80) == 0;
		byte c = (m_CPU->m_Registers.F & FC) ? 1 : 0;
		word w = word(a) - word(b) - word(c);
		bool pw = (w & 0x80) == 0;
		byte o = (pa != pb && pa != pw) ? 1 : 0;
		byte r = byte(w);
		byte h = ((a & 0x0F) - (b & 0x0F) - c) > 0x0F ? 1 : 0;
		c = (w > 0xFF) ? 1 : 0;
		m_CPU->assign_alu_flags(r, c, h, o);
		return r;
	}

	byte ALU::AND(byte a, byte b)
	{
		byte res = a & b;
		m_CPU->assign_alu_flags(res, 0, 0, 0);
		return res;
	}

	byte ALU::OR(byte a, byte b)
	{
		byte res = a | b;
		m_CPU->assign_alu_flags(res, 0, 0, 0);
		return res;
	}

	byte ALU::XOR(byte a, byte b)
	{
		byte res = a ^ b;
		m_CPU->assign_alu_flags(res, 0, 0, 0);
		return res;
	}

	word ALU::W_ADD(word a, word b)
	{
		dword d = dword(a) + dword(b);
		word r = word(d);
		byte c = (d > 0xFFFF) ? FC : 0;
		byte h = ((a & 0xFFF) + (b & 0xFFF)) > 0xFFF ? FH : 0;
		m_CPU->assign_flags(FH|FN|FC,c|h);
		return r;
	}

	word ALU::W_ADC(word a, word b)
	{
		bool pa = (a & 0x8000) == 0;
		bool pb = (b & 0x8000) == 0;
		dword c = (m_CPU->m_Registers.F & FC) ? 1 : 0;
		dword d = dword(a) + dword(b) + c;
		bool pd = (d & 0x8000) == 0;
		byte o = (pa == pb && pa != pd) ? FPV : 0;
		word r = word(d);
		byte h = ((a & 0x0FFF) + (b & 0x0FFF) + c) > 0x0FFF ? FH : 0;
		byte s = (r & 0x8000) != 0 ? FS : 0;
		c = (d > 0xFFFF) ? FC : 0;
		byte z = (r == 0 ? FZ : 0);
		m_CPU->assign_flags(FS|FZ|FH|FPV|FN|FC,s|z|h|o|c);
		return r;
	}

	word ALU::W_SUB(word a, word b)
	{
		throw std::runtime_error("Unsupported");
	}

	word ALU::W_SBC(word a, word b)
	{
		bool pa = (a & 0x8000) == 0;
		bool pb = (b & 0x8000) == 0;
		dword c = (m_CPU->m_Registers.F & FC) ? 1 : 0;
		dword d = dword(a) - dword(b) - c;
		bool pd = (d & 0x8000) == 0;
		byte o = (pa != pb && pa != pd) ? FPV : 0;
		word r = word(d);
		byte h = ((a & 0x0FFF) - (b & 0x0FFF) - c) > 0x0FFF ? FH : 0;
		byte s = (r & 0x8000) != 0 ? FS : 0;
		c = (d > 0xFFFF) ? FC : 0;
		byte z = (r == 0 ? FZ : 0);
		m_CPU->assign_flags(FS | FZ | FH | FPV | FN | FC, s | z | h | o | c);
		return r;
	}

	word ALU::W_AND(word a, word b) { throw std::runtime_error("Unsupported"); }
	word ALU::W_OR(word a, word b) { throw std::runtime_error("Unsupported"); }
	word ALU::W_XOR(word a, word b) { throw std::runtime_error("Unsupported"); }


	//byte ALU::CP(byte a, byte b){}
	
	word ALU::W_INC(word a)
	{
		return a + 1;
	}

	word ALU::W_DEC(word a)
	{
		return a - 1;
	}

	byte ALU::INC(byte a)
	{
		byte c = (m_CPU->m_Registers.F & FC) ? 1 : 0;
		a++;
		m_CPU->assign_alu_flags(a, c, a == 16 ? 1 : 0, a == 0x80 ? 1 : 0);
		return a;
	}

	byte ALU::DEC(byte a)
	{
		byte c = (m_CPU->m_Registers.F & FC) ? 1 : 0;
		byte h = (a & 0x0F) == 0 ? 1 : 0;
		a--;
		m_CPU->assign_alu_flags(a, c, h, a == 0x7F ? 1 : 0);
		return a;
	}

	byte ALU::RLC(byte a)
	{
		byte h = a >> 7;
		m_CPU->assign_flags(FC | FN | FH, h ? FC : 0);
		return (a << 1) | h;
	}

	byte ALU::RLA(byte a)
	{
		byte h = a >> 7;
		byte l = (m_CPU->m_Registers.F & FC ? 1 : 0);
		m_CPU->assign_flags(FC | FN | FH, h ? FC : 0);
		return (a << 1) | l;
	}

	byte ALU::RRC(byte a)
	{
		byte l = a & 1;
		m_CPU->assign_flags(FC | FN | FH, l ? FC : 0);
		return (a >> 1) | (l<<7);
	}

	byte ALU::RRA(byte a)
	{
		byte l = a & 1;
		byte c = (m_CPU->m_Registers.F & FC ? 0x80 : 0);
		m_CPU->assign_flags(FC | FN | FH, l ? FC : 0);
		return (a >> 1) | c;
	}

	byte ALU::SLA(byte a)
	{
		byte h = a >> 7;
		a <<= 1;
		byte flags = (h ? FC : 0) | (a == 0 ? FZ : 0) | ((a & 0x80) != 0 ? FS : 0) | (even(a)?FPV:0);
		m_CPU->assign_flags(0xFF, flags);
		return a;
	}

	byte ALU::SRA(byte a)
	{
		byte h = a & 0x80;
		byte flags = ((a & 1) ? FC : 0);
		a = (a >> 1) | h;
		flags |= (a == 0 ? FZ : 0) | (h ? FS : 0) | (even(a) ? FPV : 0);
		m_CPU->assign_flags(0xFF, flags);
		return a;
	}

	byte ALU::SRL(byte a)
	{
		byte flags = ((a & 1) ? FC : 0);
		a = (a >> 1);
		flags |= (a == 0 ? FZ : 0) | (even(a) ? FPV : 0);
		m_CPU->assign_flags(0xFF, flags);
		return a;
	}

	CPU::CPU()
		: m_RAM(65536,0)
		, m_CacheClearAddresses(65536,0xFFFF)
		, alu(this)
	{
		setup_references();
		setup_instructions();
	}

	void CPU::load_ram(word address, const std::vector<byte>& data)
	{
		for(size_t i=0;i<data.size();++i)
			m_RAM[address++]=data[i];
	}

	instruction_ptr	CPU::parse_instruction(word address)
	{
		OpcodeNode* node = &m_OpcodeRoot;
		byte size = 0;
		while (!node->create)
		{
			if (node->children.empty()) throw std::runtime_error("Invalid opcode");
			size += 1 + node->skip;
			address += node->skip;
			byte b = m_RAM[address++];
			node = &(node->children[b]);
		}
		return node->create(this, size + node->skip, node->operands);
	}

	void CPU::process_instruction()
	{
		auto it = m_InstructionCache.find(m_Special.PC);
		instruction_ptr instruction;
		if (it != m_InstructionCache.end())
		{
			instruction = it->second;
		}
		else
		{
			instruction = parse_instruction(m_Special.PC);
			m_InstructionCache[m_Special.PC] = instruction;
			for(byte i=0;i<instruction->size();++i)
				m_CacheClearAddresses[m_Special.PC + i] = m_Special.PC;
		}
		instruction->execute();
		m_Special.PC += instruction->size();
	}

	void CPU::push(word value)
	{
		m_Special.SP -= 2;
		write_word(m_Special.SP, value);
	}

	void CPU::exx()
	{
		std::swap(m_Registers.BC, m_AltRegisters.BC);
		std::swap(m_Registers.DE, m_AltRegisters.DE);
		std::swap(m_Registers.HL, m_AltRegisters.HL);
	}

	void CPU::repeat(byte offset)
	{
		m_Special.PC -= offset;
	}

	void CPU::write_word(word address, word value)
	{
		invalidate_cache(address, 2);
		m_RAM[address++] = byte(value & 0xFF);
		m_RAM[address++] = byte(value >> 8);
	}

	void CPU::write_byte(word address, byte value)
	{
		m_RAM[address] = value;
		invalidate_cache(address, 1);
	}

	byte CPU::read_byte(word address) const
	{
		return m_RAM[address]; 
	}

	word CPU::read_word(word address) const
	{
		word h= m_RAM[address+1];
		return (h<<8) | m_RAM[address];
	}

	void CPU::copy_ram(word source_address, word destination_address)
	{
		m_RAM[destination_address] = m_RAM[source_address];
		invalidate_cache(destination_address, 1);
	}

	void CPU::reset_flags(byte flags)
	{
		m_Registers.F &= ~flags;
	}

	void CPU::set_flags(byte flags)
	{
		m_Registers.F |= flags;
	}

	void CPU::assign_flags(byte mask, byte values)
	{
		m_Registers.F &= ~mask;
		m_Registers.F |= (values & mask);
	}

	void CPU::assign_alu_flags(byte res, byte c, byte h, byte o)
	{
		byte flags = (c ? FC : 0) | (h ? FH : 0) | (res == 0 ? FZ : 0) | 
			         ((res & 0x80) != 0 ? FS : 0) | (o?FPV:0);
		assign_flags(FC | FH | FZ | FS | FPV, flags);
	}

	void CPU::register_opcode(const std::vector<byte>& opcodes, const std::vector<byte>& mask,
							  instruction_create create_function,
							  const std::vector<accessor_ptr>& operands)
	{
		assert(opcodes.size() == mask.size());
		for (auto& a : operands)
		{
			if (!a) throw std::runtime_error("Invalid operand");
		}
		OpcodeNode* node = &m_OpcodeRoot;
		for (size_t i = 0; i < opcodes.size(); ++i)
		{
			if (mask[i])
			{
				if (node->children.empty()) node->children.resize(256);
				node = &(node->children[opcodes[i]]);
			}
			else node->skip++;
		}
		node->create = create_function;
		node->operands = operands;
	}

	void CPU::invalidate_cache(word address, byte size)
	{
		for(;size>0;--size, ++address)
		{
			auto& c = m_CacheClearAddresses[address];
			if (c != 0xFFFF)
			{
				m_InstructionCache.erase(c);
				c = 0xFFFF;
			}
		}
	}

	byte CPU::input(byte port)
	{
		if (m_IOController)
			return m_IOController->in(port);
		return 0;
	}

	void CPU::output(byte port, byte value)
	{
		if (m_IOController)
			m_IOController->out(port, value);
	}

}

