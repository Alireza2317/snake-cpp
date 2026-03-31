#include "core/world.hpp"
#include <algorithm>
#include <cstdint>
#include <print>
#include <random>
#include <vector>

World::World(uint16_t width, uint16_t height, std::vector<Position> obstacles)
	: m_width(width), m_height(height), m_obstacles(std::move(obstacles)) {
}

bool World::is_in_bounds(Position pos) const {
	return pos.x >= 0 and pos.y >= 0 and pos.x < m_width and pos.y < m_height;
}

bool World::is_member(const Position& pos, std::vector<Position> positions) {
	return std::ranges::contains(positions, pos);
}

bool World::is_occupied(Position pos, const std::vector<Position>& exclude_positions) const {
	if (not is_in_bounds(pos)) {
		std::println("Position ({}, {}) is out of bounds!", pos.x, pos.y);
		return true;
	}
	return is_member(pos, m_obstacles) or is_member(pos, exclude_positions);
}

void World::spawn_food(const std::vector<Position>& exclude_positions) {
	std::uniform_int_distribution<int16_t> rnd_x(0, m_width - 1);
	std::uniform_int_distribution<int16_t> rnd_y(0, m_height - 1);

	do {
		food = {rnd_x(m_rng), rnd_y(m_rng)};

	} while (is_occupied(food, exclude_positions));
}
