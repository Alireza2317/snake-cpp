#include "core/world.hpp"
#include <algorithm>
#include <cstdint>
#include <print>
#include <vector>

World::World(uint16_t width, uint16_t height, std::vector<Position> obstacles)
	: m_width(width), m_height(height), m_obstacles(std::move(obstacles)) {
}

