#include "accessors.h"
#include "z80.h"

namespace z80sim
{
	class SignedByteAccessor : public DataAccessor
	{
		accessor_ptr m_Base;
	public:
		SignedByteAccessor(accessor_ptr a)
			: m_Base(a)
		{}

		virtual word read() const override
		{
			word w = m_Base->read();
			if ((w & 0x80) != 0) w |= 0xFF00;
			return w;
		}

		virtual void write(word value) override {}
	};

	accessor_ptr Signed(accessor_ptr a)
	{
		return std::make_shared<SignedByteAccessor>(a);
	}

	template<typename T>
	RAMAccessor<T>::RAMAccessor(CPU* cpu, word address)
		: BasicAccessor(cpu->get_ram_pointer<T>(address))
		, m_CPU(cpu)
		, m_Address(address)
	{}

	template<typename T>
	void RAMAccessor<T>::write(T b)
	{
		BasicAccessor<T>::write(b);
		m_CPU->invalidate_cache(m_Address, sizeof(T));
	}

	IndirectAccessor::IndirectAccessor(CPU* cpu, accessor_ptr pointer, short offset)
		: m_CPU(cpu)
		, m_Pointer(pointer)
		, m_Offset(offset)
	{}

	IndirectAccessor::IndirectAccessor(CPU* cpu, accessor_ptr pointer, accessor_ptr offset)
		: m_CPU(cpu)
		, m_Pointer(pointer)
		, m_Offset(0)
		, m_IndirectOffset(offset)
	{}

	word IndirectAccessor::read() const
	{
		word address = m_Pointer->read() + (m_IndirectOffset ? m_IndirectOffset->read() : m_Offset);
		return m_CPU->read_byte(address);
	}

	void IndirectAccessor::write(word value)
	{
		word address = m_Pointer->read() + (m_IndirectOffset ? m_IndirectOffset->read() : m_Offset);
		m_CPU->write_byte(address, byte(value));
	}

	bool IndirectAccessor::is_literal() const
	{
		return m_Offset > 0;
	}


	IndirectAccessorW::IndirectAccessorW(CPU* cpu, accessor_ptr pointer, short offset)
		: m_CPU(cpu)
		, m_Pointer(pointer)
		, m_Offset(offset)
	{}

	IndirectAccessorW::IndirectAccessorW(CPU* cpu, accessor_ptr pointer, accessor_ptr offset)
		: m_CPU(cpu)
		, m_Pointer(pointer)
		, m_Offset(0)
		, m_IndirectOffset(offset)
	{}

	word IndirectAccessorW::read() const
	{
		word address = m_Pointer->read() + (m_IndirectOffset ? m_IndirectOffset->read() : m_Offset);
		return m_CPU->read_word(address);
	}

	void IndirectAccessorW::write(word value)
	{
		word address = m_Pointer->read() + (m_IndirectOffset ? m_IndirectOffset->read() : m_Offset);
		m_CPU->write_word(address, value);
	}


}
