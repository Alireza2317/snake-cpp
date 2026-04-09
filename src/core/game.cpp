#include "core/game.hpp"
#include "common/types.hpp"
#include "core/snake.hpp"
#include "core/world.hpp"

SnakeGame::SnakeGame() : SnakeGame(Snake(), World()) {
}

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
	if (m_world.is_occupied(head) or m_snake.hit_self()) {
		result.collision = true;
		m_state = GameState::GameOver;
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
			m_snake.attempt_turn(Direction::Left);
			break;
		case Command::MoveUp:
			m_snake.attempt_turn(Direction::Up);
			break;
		case Command::MoveRight:
			m_snake.attempt_turn(Direction::Right);
			break;
		case Command::MoveDown:
			m_snake.attempt_turn(Direction::Down);
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

const Snake& SnakeGame::get_snake() const {
	return m_snake;
}

const World& SnakeGame::get_world() const {
	return m_world;
}

uint16_t SnakeGame::get_score() const {
	return m_score;
}

snake::common::GameState SnakeGame::get_state() const {
	return m_state;
}