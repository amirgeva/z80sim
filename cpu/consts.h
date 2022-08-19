#pragma once

#include "types.h"

namespace z80sim
{
	constexpr byte FC = 1;
	constexpr byte FN = 1 << 1;
	constexpr byte FPV = 1 << 2;
	constexpr byte FH = 1 << 4;
	constexpr byte FZ = 1 << 6;
	constexpr byte FS = 1 << 7;
}