#pragma once
#include "common/types.hpp"
#include "interfaces/renderer.hpp"
#include <SFML/Graphics.hpp>

class SFMLRenderer : public IRenderer {
  private:
	sf::RenderWindow m_window;

  public:
	SFMLRenderer(uint16_t width, uint16_t height, const std::string& title);

	virtual void clear() override;
	virtual void draw_square(snake::common::Position pos, snake::common::Color color) override;
	virtual void display() override;

	virtual bool is_open() const override;
	virtual snake::common::Command poll_command() override;
};
