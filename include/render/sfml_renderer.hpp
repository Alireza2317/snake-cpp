#pragma once
#include "common/types.hpp"
#include "interfaces/renderer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

class SFMLRenderer : public IRenderer {
  private:
	sf::RenderWindow m_window;
	sf::Font m_font;

  public:
	SFMLRenderer(uint16_t width, uint16_t height, const std::string& title);

	virtual void clear() override;
	virtual void draw_square(snake::common::Position pos, snake::common::Color color) override;
	virtual void put_text(
		const std::string& text,
		snake::common::Position pos,
		uint8_t size,
		snake::common::Color color) override;
	virtual void display() override;
	virtual void close() override;
	virtual bool is_open() const override;
	virtual snake::common::Command poll_command() override;
};
