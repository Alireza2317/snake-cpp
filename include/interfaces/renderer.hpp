#pragma once
#include "common/types.hpp"
#include <string>

class IRenderer {
  public:
	virtual ~IRenderer() = default;

	virtual void clear() = 0;
	virtual void draw_square(snake::common::Position pos, snake::common::Color color) = 0;
	virtual void put_text(
		const std::string& text,
		snake::common::Position pos,
		uint8_t size,
		snake::common::Color color);
	virtual void display() = 0;
	virtual void close() = 0;
	virtual bool is_open() const = 0;
	virtual snake::common::Command poll_command() = 0;
};