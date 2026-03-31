#include "core/game.hpp"
#include "common/config.hpp"
#include "common/types.hpp"
#include "core/snake.hpp"
#include "core/world.hpp"
#include "interfaces/renderer.hpp"

SnakeGame::SnakeGame(Snake snake, World world)
	: m_snake(std::move(snake)), m_world(std::move(world)) {
	m_world.spawn_food(m_snake.parts);
}

StepResult SnakeGame::step() {
	StepResult result;

	if (m_state != GameState::Running) {
		return result;
	}

	m_snake.move();
	Position head = m_snake.parts.front();

	// check collisions
	if (not m_world.is_occupied(head)) {
		result.collision = true;
		return result;
	}

	// check eating food
	if (head == m_world.food) {
		result.food_eaten = true;
		m_snake.grow();
		m_score++;

		m_world.spawn_food(m_snake.parts);
	}

	return result;
}

bool SnakeGame::is_game_over() const {
	return m_state == GameState::GameOver;
}

void SnakeGame::handle_command(Command cmd) {
	if (m_state == GameState::GameOver) {
		return;
	}

	if (cmd == Command::Quit) {
		m_state = GameState::GameOver;
		return;
	}

	if (cmd == Command::TogglePause) {
		if (m_state == GameState::Running) {
			m_state = GameState::Paused;
		} else if (m_state == GameState::Paused) {
			m_state = GameState::Running;
		}
		return;
	}

	if (m_state != GameState::Running) {
		return;
	}

	switch (cmd) {
		case Command::MoveLeft:
			m_snake.turn(Direction::Left);
			break;
		case Command::MoveUp:
			m_snake.turn(Direction::Up);
			break;
		case Command::MoveRight:
			m_snake.turn(Direction::Right);
			break;
		case Command::MoveDown:
			m_snake.turn(Direction::Down);
			break;
		default:
			return;
	}
}
void SnakeGame::reset() {
	m_snake = Snake();

	m_score = 0;
	m_state = GameState::Running;
	m_world.spawn_food(m_snake.parts);
}

void SnakeGame::render(IRenderer& renderer) {
	renderer.draw_square(m_world.food, snake::config::colors::FOOD);

	renderer.draw_square(m_snake.parts.front(), snake::config::colors::SNAKE_HEAD);
	for (auto it = m_snake.parts.begin() + 1; it < m_snake.parts.end(); it++) {
		renderer.draw_square(*it, snake::config::colors::SNAKE);
	}
}