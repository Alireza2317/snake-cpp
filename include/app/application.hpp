#pragma once
#include "common/config.hpp"
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
	while (m_renderer->is_open()) {
		m_renderer->handle_events();

		m_game.step();

		m_renderer->clear();
		m_game.render(*m_renderer);

		m_renderer->display();
	}
}