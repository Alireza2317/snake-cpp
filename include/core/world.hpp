#pragma once
#include "common/types.hpp"
#include <cstdint>
#include <random>
#include <vector>

class World {
	using Position = snake::common::Position;

  private:
	uint16_t m_width;
	uint16_t m_height;
	std::vector<Position> m_obstacles;
	std::mt19937 m_rng = std::mt19937{std::random_device{}()};

  public:
	Position food;
	World(uint16_t width, uint16_t height, std::vector<Position> obstacles);
	static bool is_member(const Position& pos, std::vector<Position> positions);
	bool is_occupied(Position pos, const std::vector<Position>& exclude_positions = {}) const;
	bool is_in_bounds(Position pos) const;
	void spawn_food(const std::vector<Position>& exclude_positions);
};