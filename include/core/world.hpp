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
	Position m_food;
	std::mt19937 m_rng = std::mt19937{std::random_device{}()};

  public:
	World(uint16_t width, uint16_t height, std::vector<Position> obstacles);
	static bool is_member(const Position& pos, std::vector<Position> positions);
	bool is_occupied(Position pos, const std::vector<Position>& exclude_positions = {});
	bool is_in_bounds(Position pos);
	void spawn_food(const std::vector<Position>& exclude_positions);
};