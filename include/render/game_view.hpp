#pragma once
#include "common/config.hpp"
#include "common/types.hpp"
#include "core/game.hpp"
#include "core/world.hpp"
#include "interfaces/renderer.hpp"
#include <format>

class GameView {
  public:
	void draw(const SnakeGame& game, IRenderer& renderer) {
		draw_walls(game.get_world(), renderer);
		draw_snake(game.get_snake(), renderer);
		draw_food(game.get_world().food, renderer);
		draw_ui(game, renderer);
	}

  private:
	static snake::common::Position to_screen(snake::common::Position pos) {
		return {
			static_cast<int16_t>(pos.x + snake::config::ui::GAME_VIEW_OFFSET.x),
			static_cast<int16_t>(pos.y + snake::config::ui::GAME_VIEW_OFFSET.y)};
	}

	void draw_snake(const Snake& snake, IRenderer& renderer) {
		for (const auto& part : snake.parts) {
			renderer.draw_square(to_screen(part), snake::config::colors::SNAKE);
		}
		renderer.draw_square(to_screen(snake.parts.front()), snake::config::colors::SNAKE_HEAD);
	}

	void draw_walls(const World& world, IRenderer& renderer) {
		using namespace snake::config;

		for (int x = -1; x <= world.width(); x++) {
			renderer.draw_square(to_screen({(int16_t)x, -1}), colors::WALL);
			renderer.draw_square(to_screen({(int16_t)x, (int16_t)world.height()}), colors::WALL);
		}
		for (int y = 0; y < world.height(); y++) {
			renderer.draw_square(to_screen({-1, (int16_t)y}), colors::WALL);
			renderer.draw_square(to_screen({(int16_t)world.width(), (int16_t)y}), colors::WALL);
		}

		// Obstacles
		for (const auto& obs : world.obstacles()) {
			renderer.draw_square(to_screen(obs), colors::WALL);
		}

	}

	void draw_food(snake::common::Position food, IRenderer& renderer) {
		renderer.draw_square(to_screen(food), snake::config::colors::FOOD);
	}

	void draw_ui(const SnakeGame& game, IRenderer& renderer) {
		renderer.put_text(
			std::format("Score: {}", game.get_score()),
			snake::config::ui::SCORE_POS,
			snake::common::Color::White);

		if (game.get_state() == snake::common::GameState::GameOver) {
			renderer.put_text(
				"Game Over! Press R to reset.",
				snake::config::ui::INFO_POS,
				snake::common::Color::White);
		} else if (game.get_state() == snake::common::GameState::Paused) {
			renderer.put_text(
				"Paused! Press P to unpause.",
				snake::config::ui::INFO_POS,
				snake::common::Color::White);
		}
	}
};