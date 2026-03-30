#pragma once
#include "common/types.hpp"
#include <vector>

class Snake {
	using Direction = snake::common::Direction;
	using Position = snake::common::Position;

  private:
	Position left_over_tail;
	void move_head();

  public:
	std::vector<Position> parts;
	Direction direction{Direction::Right};

	void move();
	void turn(Direction new_direction);
};