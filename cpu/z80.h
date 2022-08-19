#pragma once

#include <unordered_map>
#include <vector>
#include <functional>
#include "accessors.h"

namespace z80sim
{
	class IOController
	{
	public:
		virtual ~IOController() {}
		virtual void out(byte port, byte data) = 0;
		virtual byte in(byte port) = 0;
		virtual void periodic() = 0;
	};
	typedef std::shared_ptr<IOController> io_ctrl_ptr;

	class Instruction
	{
		byte m_Size;
	public:
		Instruction(byte size) : m_Size(size) {}
		virtual ~Instruction() {}
		virtual void execute() = 0;
		byte size() const { return m_Size; }
	};

	typedef std::shared_ptr<Instruction> instruction_ptr;
	typedef std::function<instruction_ptr(CPU*, byte, const std::vector<accessor_ptr>&)> instruction_create;

	class ALU
	{
		CPU* m_CPU;
	public:
		ALU(CPU* cpu);

		byte ADD(byte a, byte b);
		byte ADC(byte a, byte b);
		byte SUB(byte a, byte b);
		byte SBC(byte a, byte b);
		byte AND(byte a, byte b);
		byte OR(byte a, byte b);
		byte XOR(byte a, byte b);

		word W_ADD(word a, word b);
		word W_ADC(word a, word b);
		word W_SUB(word a, word b);
		word W_SBC(word a, word b);
		word W_AND(word a, word b);
		word W_OR(word a, word b);
		word W_XOR(word a, word b);
		//byte CP(byte a, byte b);
		byte INC(byte a);
		byte DEC(byte a);
		word W_INC(word a);
		word W_DEC(word a);

		byte RLC(byte a);
		byte RLA(byte a);
		byte RRC(byte a);
		byte RRA(byte a);
		byte SLA(byte a);
		byte SRA(byte a);
		byte SRL(byte a);
	};

	class CPU
	{
		struct BaseRegisterFile
		{
			BaseRegisterFile()
				: AF(0), BC(0), DE(0), HL(0)
			{}

			union {
				struct { byte F, A;	};
				word AF;
			};
			union {
				struct { byte C, B; };
				word BC;
			};
			union {
				struct { byte E, D; };
				word DE;
			};
			union {
				struct { byte L, H; };
				word HL;
			};
		};

		struct SpecialPurpose
		{
			SpecialPurpose() : I(0), R(0), IX(0), IY(0), SP(0), PC(0) {}
			byte I, R;
			word IX, IY, SP, PC;
		};

		std::vector<byte>								m_RAM;
		std::unordered_map<word,instruction_ptr>		m_InstructionCache;
		std::vector<word>								m_CacheClearAddresses;
		io_ctrl_ptr										m_IOController;

		struct OpcodeNode
		{
			std::vector<OpcodeNode>			children;
			instruction_create				create;
			std::vector<accessor_ptr>		operands;
			byte							skip = 0;
		} m_OpcodeRoot;

		void			setup_references();
		void			setup_instructions();
		instruction_ptr	parse_instruction(word address);
	public:
		CPU();

		template<typename T>
		T* get_ram_pointer(word address) { return reinterpret_cast<T*>(&m_RAM[address]); }
		void load_ram(word address, const std::vector<byte>& data);
		void process_instruction();
		void invalidate_cache(word address, byte size);
		void register_opcode(const std::vector<byte>& opcodes, const std::vector<byte>& mask,
							 instruction_create create_function,
							 const std::vector<accessor_ptr>& operands);

		void set_io_controller(io_ctrl_ptr io) { m_IOController = io; }
		void interrupts(bool state) {}
		void set_interrupt_mode(word mode) {}
		byte input(byte port);
		void output(byte port, byte value);
		void exx();
		void repeat(byte offset);
		void push(word value);
		byte read_byte(word address) const;
		word read_word(word address) const;
		void write_word(word address, word value);
		void write_byte(word address, byte value);
		void copy_ram(word source_address, word destination_address);
		void reset_flags(byte flags);
		void set_flags(byte flags);
		void assign_flags(byte mask, byte values);
		void assign_alu_flags(byte res, byte c, byte h, byte o);

		ALU												alu;
		std::unordered_map<std::string, accessor_ptr>	m_Refs, m_Flags;
		BaseRegisterFile								m_Registers;
		BaseRegisterFile								m_AltRegisters;
		SpecialPurpose									m_Special;
	};


} // namespace z80sim