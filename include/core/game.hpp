#pragma once
#include "common/types.hpp"
#include "core/snake.hpp"
#include "core/world.hpp"
#include "interfaces/renderer.hpp"

struct StepResult {
	bool food_eaten{false};
	bool collision{false};
};

class SnakeGame {
	using Position = snake::common::Position;
	using Direction = snake::common::Direction;
	using GameState = snake::common::GameState;
	using Command = snake::common::Command;
	using Color = snake::common::Color;

  private:
	Snake m_snake;
	World m_world;
	uint16_t m_score{0};
	GameState m_state{GameState::Running};

  public:
	SnakeGame(Snake snake, World world);
	StepResult step();
	void render(IRenderer& renderer);
	void handle_command(Command cmd);
	void reset();
	bool is_game_over() const;
};