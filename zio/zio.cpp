#include "zio.h"
#include "zgpu.h"
#include "protocol.h"

using z80sim::CPU;
using z80sim::IOController;
using z80sim::byte;

class ZIoController : public IOController
{
	CPU*									m_CPU;
	OpenCVGPU								m_GPU;
	Protocol								m_Protocol;
	std::chrono::steady_clock::time_point	m_LastTime;
public:
	ZIoController(CPU* cpu)
		: m_CPU(cpu)
		, m_Protocol(&m_GPU)
		, m_LastTime(std::chrono::steady_clock::now())
	{}

	virtual void out(byte port, byte data) override
	{
		m_Protocol.add_byte(data);
	}

	virtual byte in(byte port) override
	{
		return 0;
	}

	virtual void periodic() override
	{
		auto now = std::chrono::steady_clock::now();
		int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_LastTime).count();
		if (elapsed >= 10)
		{
			word timer = m_CPU->read_word(0x00EC);
			m_CPU->write_word(0x00EC, ++timer);
			m_LastTime = now;
		}
		byte k=m_GPU.get_key();
		if (k != 255 && k != 0)
		{
			m_Protocol.log_key(k);
			word address = 0x100 + m_CPU->read_byte(0xEE);
			m_CPU->write_byte(address, k);
			m_CPU->write_byte(0xEE, byte(address + 1));
		}
	}
};



z80sim::io_ctrl_ptr create_io(CPU* cpu)
{
	return std::make_shared<ZIoController>(cpu);
}
