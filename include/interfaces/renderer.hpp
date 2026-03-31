#pragma once
#include "common/types.hpp"

class IRenderer {
  public:
	virtual ~IRenderer() = default;

	virtual void clear() = 0;
	virtual void draw_square(snake::common::Position pos, snake::common::Color color) = 0;
	virtual void display() = 0;

	virtual bool is_open() const = 0;
	virtual snake::common::Command poll_command() = 0;
};