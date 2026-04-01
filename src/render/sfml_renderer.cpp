#include "render/sfml_renderer.hpp"
#include "common/config.hpp"
#include "common/types.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

static sf::Color to_sf_color(snake::common::Color color) {
	using Color_snake = snake::common::Color;
	switch (color) {
		case Color_snake::Black:
			return sf::Color::Black;
		case Color_snake::White:
			return sf::Color::White;
		case Color_snake::Green:
			return sf::Color::Green;
		case Color_snake::Gray:
			return sf::Color(50, 50, 50, 255);
		case Color_snake::Red:
			return sf::Color::Red;
		case Color_snake::Blue:
			return sf::Color::Blue;
		case Color_snake::Yellow:
			return sf::Color::Yellow;
		case Color_snake::Orange:
			return sf::Color(255, 150, 50, 255);
		case Color_snake::Violet:
			return sf::Color::Magenta;
		case Color_snake::Cyan:
			return sf::Color::Cyan;
		case Color_snake::Transparent:
			return sf::Color::Transparent;
	}
	return sf::Color::Black;
}

SFMLRenderer::SFMLRenderer(uint16_t width, uint16_t height, const std::string& title)
	: m_window(sf::VideoMode(width, height), title) {
	m_window.setFramerateLimit(snake::config::window::MAX_FPS);
}
void SFMLRenderer::clear() {
	m_window.clear(sf::Color::Black);
}
void SFMLRenderer::draw_square(snake::common::Position pos, snake::common::Color color) {
	constexpr auto TILE_SIZE = snake::config::game::TILE_SIZE;

	sf::RectangleShape shape({TILE_SIZE, TILE_SIZE});
	shape.setPosition(pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	shape.setFillColor(to_sf_color(color));

	m_window.draw(shape);
}
void SFMLRenderer::display() {
	m_window.display();
}
bool SFMLRenderer::is_open() const {
	return m_window.isOpen();
}
snake::common::Command SFMLRenderer::poll_command() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			close();
		}
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::Up:
				case sf::Keyboard::W:
					return snake::common::Command::MoveUp;
				case sf::Keyboard::Down:
				case sf::Keyboard::S:
					return snake::common::Command::MoveDown;
				case sf::Keyboard::Right:
				case sf::Keyboard::D:
					return snake::common::Command::MoveRight;
				case sf::Keyboard::Left:
				case sf::Keyboard::A:
					return snake::common::Command::MoveLeft;
				case sf::Keyboard::P:
					return snake::common::Command::TogglePause;
				case sf::Keyboard::R:
					return snake::common::Command::Restart;
				case sf::Keyboard::Escape:
				case sf::Keyboard::Q:
					return snake::common::Command::Quit;
				default:
					break;
			}
		}
	}
	return snake::common::Command::None;
}

void SFMLRenderer::close() {
	m_window.close();
}