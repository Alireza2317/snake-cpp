#pragma once
#include "common/config.hpp"
#include "common/types.hpp"
#include "core/game.hpp"
#include "interfaces/renderer.hpp"
#include "render/sfml_renderer.hpp"
#include <memory>
#include <string>

class App {
  private:
	std::unique_ptr<IRenderer> m_renderer;
	SnakeGame m_game;

  public:
	App();
	void run();
};

/// ------ IMPLEMENTATIONS ------

inline App::App()
	: m_renderer(std::make_unique<SFMLRenderer>(
		  snake::config::window::WIDTH,
		  snake::config::window::HEIGHT,
		  std::string(snake::config::window::TITLE))),
	  m_game(SnakeGame()) {
}

inline void App::run() {
	sf::Clock clock;
	sf::Time time = sf::Time::Zero;
	const sf::Time time_per_step = sf::seconds(snake::config::game::DELAY);

	while (m_renderer->is_open()) {
		time += clock.restart();

		snake::common::Command cmd = m_renderer->poll_command();

		if (cmd == snake::common::Command::Quit) {
			m_renderer->close();
			break;
		}
		if (cmd == snake::common::Command::Restart) {
			m_game.reset();
			continue;
		}

		m_game.handle_command(cmd);

		while (time >= time_per_step) {
			time -= time_per_step;
			m_game.step();
		}

		m_renderer->clear();
		m_game.render(*m_renderer);

		m_renderer->display();
	}
}