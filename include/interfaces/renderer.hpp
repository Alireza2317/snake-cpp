#pragma once

class IRenderer {
  public:
	virtual ~IRenderer() = default;

	virtual void clear() = 0;
	virtual void draw_square() = 0;
	virtual void display() = 0;

	virtual bool is_open() const = 0;
	virtual void handle_events() = 0;
};