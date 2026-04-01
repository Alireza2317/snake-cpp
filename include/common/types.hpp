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

	enum class Color {
		White,
		Black,
		Gray,
		Yellow,
		Orange,
		Green,
		Blue,
		Red,
		Violet,
		Cyan,
		Transparent
	};

	enum class Direction { Left, Up, Right, Down };

	enum class GameState { Running, Paused, GameOver };

	enum class Command { None, MoveLeft, MoveUp, MoveRight, MoveDown, TogglePause, Restart, Quit };
} // namespace snake::common