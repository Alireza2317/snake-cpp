#pragma once
#include "common/types.hpp"
#include "interfaces/renderer.hpp"
#include <cstdint>
#include <random>
#include <vector>

class World {
	using Position = snake::common::Position;

  private:
	uint16_t m_width;
	uint16_t m_height;
	std::vector<Position> m_obstacles;
	Position m_food;
	std::mt19937 m_rng;

  public:
	bool is_in_bounds(Position pos);
	void spawn_food(const std::vector<Position>& exclude_positions);
	void render(IRenderer& renderer);
};