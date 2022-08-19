#pragma once

#include <opencv2/opencv.hpp>
#include <types.h>

using z80sim::byte;
using z80sim::word;

constexpr uint16_t WIDTH = 400;
constexpr uint16_t HEIGHT = 300;
constexpr uint16_t CHAR_WIDTH = 8;
constexpr uint16_t CHAR_HEIGHT = 8;

class GPU
{
public:
	virtual ~GPU() {}
	virtual void fill_rect(word x, word y, word w, word h, byte color) = 0;
	virtual void scroll(word scan_lines) = 0;
	virtual void line(word x0, word y0, word x1, word y1, byte color) = 0;
	virtual void pixels(word x, word y, const byte* pixels, byte n) = 0;
	virtual void text(word x, word y, const byte* text, byte n, byte fg_color, byte bg_color) = 0;
	virtual void set_sprite(byte id, const byte* data) = 0;
	virtual void draw_sprite(byte id, word x, word y) = 0;
	virtual byte get_key() = 0;
};

class OpenCVGPU : public GPU
{
	cv::Mat						m_FrameBuffer;
	cv::Mat						m_ScaledBuffer;
	std::vector<cv::Mat>		m_Sprites;
	cv::Mat						m_Font;

	void paste_char(word x, word y, word ch, byte fg_color, byte bg_color);
	void update();
public:
	OpenCVGPU();
	~OpenCVGPU();
	virtual void fill_rect(word x, word y, word w, word h, byte color) override;
	virtual void scroll(word scan_lines) override;
	virtual void line(word x0, word y0, word x1, word y1, byte color) override;
	virtual void pixels(word x, word y, const byte* pixels, byte n) override;
	virtual void text(word x, word y, const byte* text, byte n, byte fg_color, byte bg_color) override;
	virtual void set_sprite(byte id, const byte* data) override;
	virtual void draw_sprite(byte id, word x, word y) override;
	virtual byte get_key() override;
};
