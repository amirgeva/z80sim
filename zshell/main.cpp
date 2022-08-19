#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <cxx/xstring.h>
#include <z80.h>
#include <zio.h>

using namespace z80sim;

std::vector<byte> load_code()
{
	std::ifstream f("C:\\prg\\github\\z80pc\\v1.6\\zos\\zos.bin", std::ios::in | std::ios::binary);
	f.seekg(0, std::ios::end);
	size_t n = f.tellg();
	f.seekg(0);
	std::vector<byte> code(n);
	f.read((char*)&code[0], n);
	return code;
}

cxx::xstring format_hex(byte b)
{
	std::ostringstream os;
	os << std::hex << unsigned(b);
	cxx::xstring s = os.str();
	if (s.length() < 2) s = "0" + s;
	return s;
}

byte hex(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'a' && c <= 'f') return 10 + c - 'a';
	if (c >= 'A' && c <= 'F') return 10 + c - 'A';
	return 0;
}

byte parse_byte(const cxx::xstring& s)
{
	return (hex(s[0]) << 4) | hex(s[1]);
}

std::vector<byte> parse_code(const cxx::xstring& data)
{
	std::vector<byte> code;
	size_t i = 0, n = data.size();
	code.reserve(n / 2);
	while (i < (n - 1))
	{
		code.push_back(parse_byte(data.substr(i, 2)));
		i += 2;
	}
	return code;
}

#define SYNC std::lock_guard<std::mutex> g(mutex)

class Runtime
{
	bool						terminate = false;
	bool						running = false;
	bool						do_step = false;
	int							stop_addr = -1;
	std::shared_ptr<CPU>		cpu;
	io_ctrl_ptr					io;
	//std::thread					thread;
	std::mutex					mutex;

	void send_step_response()
	{
		std::vector<word> data;
		data.push_back(cpu->m_Special.PC);
		data.push_back(cpu->m_Registers.AF);
		data.push_back(cpu->m_Registers.BC);
		data.push_back(cpu->m_Registers.DE);
		data.push_back(cpu->m_Registers.HL);
		data.push_back(cpu->m_Special.SP);
		data.push_back(cpu->m_Special.IX);
		data.push_back(cpu->m_Special.IY);
		cxx::xstring res;
		const byte* bdata = reinterpret_cast<const byte*>(&data[0]);
		for (size_t i = 0; i < (2 * data.size()); i += 2)
		{
			res += format_hex(bdata[i]);
			res += format_hex(bdata[i + 1]);
		}
		std::cout << res << std::endl;
		std::cout.flush();
	}
public:
	Runtime()
//		: thread([&]() {ThreadMain(); })
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	~Runtime()
	{
		terminate = true;
//		thread.join();
	}

	bool terminated() const
	{
		return terminate;
	}


	void initialize()
	{
		cpu = std::make_shared<CPU>();
		io = create_io(cpu.get());
		cpu->set_io_controller(io);
	}

	void thread_iteration()
	{
		if (!terminate)
		{
			bool do_sleep = true;
			{
				SYNC;
				if (running)
				{
					do_sleep = false;
					for (word i = 0; i < 16384; ++i)
					{
						cpu->process_instruction();
						if (stop_addr >= 0 && cpu->m_Special.PC == stop_addr)
						{
							running = false;
							send_step_response();
							return;
						}
					}
					io->periodic();
				}
				else
				if (do_step)
				{
					do_step = false;
					cpu->process_instruction();
					io->periodic();
					send_step_response();
				}
			}
			if (do_sleep)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				io->periodic();
			}
		}
	}

	void load()
	{
		SYNC;
		cpu->load_ram(0, load_code());
	}

	void load_ram(word address, const std::vector<byte>& code)
	{
		SYNC;
		cpu->load_ram(address, code);
	}

	std::vector<byte> read_data(word address, word length)
	{
		SYNC;
		std::vector<byte> data;
		data.reserve(length);
		while (length-- > 0)
			data.push_back(cpu->read_byte(address++));
		return data;
	}

	void reset()
	{
		SYNC;
		cpu->m_Special.PC = 0;
	}

	void shutdown()
	{
		terminate = true;
	}

	void run(int stop_at_addr=-1)
	{
		SYNC;
		stop_addr = stop_at_addr;
		running = true;
	}

	void stop()
	{
		if (running)
		{
			SYNC;
			running = false;
		}
	}

	void step()
	{
		SYNC;
		do_step = true;
	}
};

Runtime rt;

void CommandThread()
{
	cxx::xstring line;
	while (line.read_line(std::cin))
	{
		cxx::xstring_tokenizer st(line, " ");
		if (st.size() == 0) continue;
		cxx::xstring cmd = st.get_next_token();
		if (cmd == "l")
		{
			rt.load();
		}
		if (cmd == "w")
		{
			word address = st.get_next_token().as<word>();
			cxx::xstring data = st.get_next_token();
			std::vector<byte> code = parse_code(data);
			rt.load_ram(address, code);
		}
		if (cmd == "r")
		{
			word address = st.get_next_token().as<word>();
			word length = st.get_next_token().as<word>();
			std::vector<byte> data = rt.read_data(address, length);
			cxx::xstring res;
			for (word i = 0; i < length; ++i)
			{
				res += format_hex(data[i]);
			}
			std::cout << res << std::endl;
			std::cout.flush();
		}
		if (cmd == "sd")
		{
			rt.shutdown();
			break;
		}
		if (cmd == "rst")
		{
			rt.reset();
		}
		if (cmd == "t")
		{
			word addr = st.get_next_token().as_int();
			rt.run(addr);
		}
		if (cmd == "run")
		{
			rt.run();
		}
		if (cmd == "s")
		{
			rt.stop();
			rt.step();
		}
	}
}

int main(int argc, char* argv[])
{
	rt.initialize();
	std::thread t([]() {CommandThread(); });
	while (!rt.terminated())
		rt.thread_iteration();
	t.join();
	return 0;
}
