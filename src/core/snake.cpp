#include "core/snake.hpp"

Snake::Snake(SnakeBody body) : parts(std::move(body)) {
}

void Snake::move_head() {
	Position head = parts.at(0);
	switch (direction) {
		case Direction::Left:
			head.x--;
			break;
		case Direction::Up:
			head.y--;
			break;
		case Direction::Right:
			head.x++;
			break;
		case Direction::Down:
			head.y++;
			break;
	}
}

void Snake::move() {
	move_head();

	m_left_over_tail = parts.back();
	parts.pop_back();
}

void Snake::turn(Direction new_direction) {
	static auto is_horizontal = [](Direction d) constexpr {
		return d == Direction::Right or d == Direction::Left;
	};

	if (is_horizontal(new_direction) != is_horizontal(direction)) {
		direction = new_direction;
	}
}

void Snake::grow() {
	parts.push_back(m_left_over_tail);
}
