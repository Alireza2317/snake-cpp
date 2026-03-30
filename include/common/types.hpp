#pragma once
#include <cstdint>

namespace snake::common {
	struct Position {
		int16_t x, y;

		bool operator==(const Position& other) const = default;

		bool is_valid() {
			return not(x < 0 or y < 0);
		}
	};

	enum class Color { White, Yellow, Orange, Green, Blue, Red, Violet, Cyan };

	enum class Direction { Left, Up, Right, Down };
} // namespace snake::common