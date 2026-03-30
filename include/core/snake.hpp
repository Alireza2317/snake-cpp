#pragma once
#include "common/types.hpp"
#include <vector>

class Snake {
	using Direction = snake::common::Direction;
	using Position = snake::common::Position;
	using SnakeBody = std::vector<Position>;

  private:
	Position left_over_tail;
	void move_head();

  public:
	SnakeBody parts;
	Direction direction{Direction::Right};

	explicit Snake(SnakeBody body);
	~Snake();

	void move();
	void turn(Direction new_direction);
};