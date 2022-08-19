#pragma once

#include <memory>
#include "types.h"

namespace z80sim
{

	class CPU;

	class DataAccessor
	{
	protected:
		bool m_IsWord = false;
	public:
		virtual ~DataAccessor() {}
		virtual bool is_word() const { return m_IsWord; }
		virtual bool is_literal() const { return false; }
		virtual word read() const = 0;
		virtual void write(word value) = 0;
	};
	typedef std::shared_ptr<DataAccessor> accessor_ptr;


	template<typename T>
	class BasicAccessor : public DataAccessor
	{
		T* m_Ptr;
	public:
		BasicAccessor(T* ptr) : m_Ptr(ptr) 
		{
			m_IsWord = (sizeof(T) == 2);
		}
		virtual word read() const override
		{
			return *m_Ptr;
		}
		virtual void write(word b) override
		{
			*m_Ptr = b;
		}
	};

	class FlagAccessor : public DataAccessor
	{
		byte* m_Flags;
		byte  m_Mask;
		bool  m_Inverted;
	public:
		FlagAccessor(byte* flags, int bit, bool inverted)
			: m_Flags(flags)
			, m_Mask(1 << bit)
			, m_Inverted(inverted)
		{}
		virtual word read() const override
		{
			bool f = (*m_Flags & m_Mask) != 0;
			return (f ^ m_Inverted ? 1 : 0);
		}
		virtual void write(word b) override
		{
			bool f = (b != 0);
			*m_Flags &= ~m_Mask;
			if (f ^ m_Inverted)
				*m_Flags |= m_Mask;
		}
	};

	class LiteralAccessor : public DataAccessor
	{
		word m_Value;
	public:
		LiteralAccessor(word value) : m_Value(value) {}
		virtual word read() const override
		{
			return m_Value;
		}
		virtual void write(word b) override
		{
		}
		virtual bool is_literal() const override
		{
			return true;
		}
	};

	template<typename T>
	class RAMAccessor : public BasicAccessor<T>
	{
		CPU* m_CPU;
		word m_Address;
	public:
		RAMAccessor(CPU* cpu, word address);
		virtual void write(T b) override;
	};

	class IndirectAccessor : public DataAccessor
	{
		CPU*				m_CPU;
		accessor_ptr		m_Pointer;
		short				m_Offset;
		accessor_ptr		m_IndirectOffset;
	public:
		IndirectAccessor(CPU* cpu, accessor_ptr pointer, short offset = 0);
		IndirectAccessor(CPU* cpu, accessor_ptr pointer, accessor_ptr offset);
		virtual word read() const override;
		virtual void write(word value) override;
		virtual bool is_literal() const override;
	};

	class IndirectAccessorW : public DataAccessor
	{
		CPU*				m_CPU;
		accessor_ptr		m_Pointer;
		short				m_Offset;
		accessor_ptr		m_IndirectOffset;
	public:
		IndirectAccessorW(CPU* cpu, accessor_ptr pointer, short offset = 0);
		IndirectAccessorW(CPU* cpu, accessor_ptr pointer, accessor_ptr offset);
		virtual word read() const override;
		virtual void write(word value) override;
	};

	accessor_ptr Signed(accessor_ptr a);


} // namespace z80sim