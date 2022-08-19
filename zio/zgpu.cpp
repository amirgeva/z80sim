#include "zgpu.h"

static const byte font_data[] = {
#include "font.inl"
};

int extend(int c)
{
	if (c & 1) return (c << 6) | 0x3F;
	return c << 6;
}

cv::Scalar parse_color(byte color)
{
	return cv::Scalar(extend((color >> 4) & 3),
					  extend((color >> 2) & 3),
					  extend((color     ) & 3));
}

cv::Vec3b parse_color_v(byte color)
{
	cv::Vec3b res;
	res[0] = extend((color >> 4) & 3);
	res[1] = extend((color >> 2) & 3);
	res[2] = extend((color) & 3);
	return res;
}


OpenCVGPU::OpenCVGPU()
	: m_FrameBuffer(300,400,CV_8UC3)
	, m_Sprites(256)
	, m_Font(256*8,8,CV_8UC1)
{
	m_FrameBuffer = cv::Scalar(0, 0, 0);
	for (int i = 0; i < 256; ++i)
		m_Sprites[i] = cv::Mat(16, 16, CV_8UC3);
	std::copy_n(font_data, 256 * 64, m_Font.data);
	cv::namedWindow("GPU");
}

OpenCVGPU::~OpenCVGPU()
{
}

byte OpenCVGPU::get_key()
{
	int key = cv::waitKey(1);
	return byte(key & 255);
}

void OpenCVGPU::fill_rect(word x, word y, word w, word h, byte color)
{
	const cv::Rect image_rect(0, 0, 400, 300);
	cv::Rect r(x, y, w, h);
	r &= image_rect;
	m_FrameBuffer(r) = parse_color(color);
	update();
}

void OpenCVGPU::scroll(word scan_lines)
{
	if (scan_lines >= 300) m_FrameBuffer = cv::Scalar(0, 0, 0);
	else
	{
		m_FrameBuffer(cv::Rect(0, scan_lines, 400, 300 - scan_lines)).clone().copyTo(
			m_FrameBuffer(cv::Rect(0, 0, 400, 300 - scan_lines)));
	}
	update();
}

void OpenCVGPU::line(word x0, word y0, word x1, word y1, byte color)
{
	cv::line(m_FrameBuffer, cv::Point(x0, y0), cv::Point(x1, y1), parse_color(color));
	update();
}

void OpenCVGPU::pixels(word x, word y, const byte* pixels, byte n)
{
	for (; n > 0 && x < WIDTH; --n, ++x, ++pixels)
	{
		m_FrameBuffer.at<cv::Vec3b>(cv::Point(x, y)) = parse_color_v(*pixels);
	}
	update();
}

void OpenCVGPU::paste_char(word x, word y, word ch, byte fg_color, byte bg_color)
{
	if ((x + 8) > WIDTH || (y + 8) > HEIGHT) return;
	cv::Vec3b fg = parse_color_v(fg_color);
	cv::Vec3b bg = parse_color_v(bg_color);
	cv::Mat img(8, 8, CV_8UC3);
	const byte* src = m_Font.ptr(ch * 8);
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j, ++src)
			img.at<cv::Vec3b>(cv::Point(j, i)) = (*src > 0 ? fg : bg);
	img.copyTo(m_FrameBuffer(cv::Rect(x, y, 8, 8)));
}

void OpenCVGPU::text(word x, word y, const byte* text, byte n, byte fg_color, byte bg_color)
{
	for (; n > 0; ++text, --n, x += 8)
	{
		paste_char(x, y, *text, fg_color, bg_color);
	}
	update();
}

void OpenCVGPU::set_sprite(byte id, const byte* data)
{
	for (int y = 0; y < 16; ++y)
		for (int x = 0; x < 16; ++x)
			m_Sprites[id].at<cv::Vec3b>(cv::Point(x, y)) = parse_color_v(*data++);
}

void OpenCVGPU::draw_sprite(byte id, word x, word y)
{
	if (x >= WIDTH || y >= HEIGHT) return;
	word w = std::min(16, WIDTH - x), h = std::min(16, HEIGHT - y);
	m_Sprites[id](cv::Rect(0,0,w,h)).copyTo(m_FrameBuffer(cv::Rect(x, y, w, h)));
	update();
}

void OpenCVGPU::update()
{
	if (!m_ScaledBuffer.data)
		m_ScaledBuffer = cv::Mat(1200, 1600, CV_8UC3);
	cv::resize(m_FrameBuffer, m_ScaledBuffer, cv::Size(1600, 1200), 0, 0, cv::INTER_NEAREST);
	cv::imshow("GPU", m_ScaledBuffer);
}
