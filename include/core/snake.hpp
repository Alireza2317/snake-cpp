#pragma once
#include "common/types.hpp"
#include <vector>

class Snake {
	using Direction = snake::common::Direction;
	using Position = snake::common::Position;
	using SnakeBody = std::vector<Position>;

  private:
	Position m_left_over_tail;
	Position get_moved_head();

  public:
	SnakeBody parts;
	Direction direction{Direction::Right};

	explicit Snake();
	explicit Snake(SnakeBody body);

	void move();
	void turn(Direction new_direction);
	void grow();
};