#include "core/snake.hpp"
#include "common/types.hpp"

using namespace snake;

Snake::Snake(SnakeBody body) : parts(std::move(body)) {
}
Snake::~Snake() {
}

common::Position Snake::get_moved_head() {
	Position new_head = parts.at(0);
	switch (direction) {
		case Direction::Left:
			new_head.x--;
			break;
		case Direction::Up:
			new_head.y--;
			break;
		case Direction::Right:
			new_head.x++;
			break;
		case Direction::Down:
			new_head.y++;
			break;
	}
	return new_head;
}

void Snake::move() {
	Position new_head_pos = get_moved_head();
	parts.insert(parts.begin(), new_head_pos);

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
