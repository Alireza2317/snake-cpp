#include "core/snake.hpp"
#include "common/config.hpp"
#include "common/types.hpp"

using namespace snake;

Snake::Snake() {
	for (int16_t i = config::game::INITIAL_SNAKE_LENGTH - 1; i >= 0; i--) {
		if (i >= config::game::NUM_TILES_X - 1) {
			break;
		}

		parts.push_back({.x = i, .y = 0});
	}
}
Snake::Snake(SnakeBody body) : parts(std::move(body)) {
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
		default:
			break;
	}
	return new_head;
}

void Snake::move() {
	static auto is_horizontal = [](Direction d) {
		return d == Direction::Right or d == Direction::Left;
	};

	if (m_pending_direction != Direction::None) {
		if (is_horizontal(m_pending_direction) != is_horizontal(direction)) {
			direction = m_pending_direction;
		}
	}

	Position new_head_pos = get_moved_head();
	parts.insert(parts.begin(), new_head_pos);

	m_left_over_tail = parts.back();
	parts.pop_back();
}

void Snake::turn(Direction new_direction) {
	m_pending_direction = new_direction;
}

void Snake::grow() {
	parts.push_back(m_left_over_tail);
}

bool Snake::hit_self() {
	for (auto it = parts.begin() + 1; it < parts.end(); it++) {
		if (parts.front() == *it) {
			return true;
		}
	}
	return false;
}