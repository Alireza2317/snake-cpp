#pragma once
#include "common/types.hpp"
#include <cstdint>
#include <string_view>

namespace snake::config {
	namespace game {
		inline constexpr float TILE_SIZE = 25.0f;
		inline constexpr uint16_t NUM_TILES_X = 32;
		inline constexpr uint16_t NUM_TILES_Y = 24;
		inline constexpr uint16_t INITIAL_SNAKE_LENGTH = 3;
		inline constexpr float FPS = 10.0f;
	} // namespace game
	namespace colors {
		using namespace snake::common;
		inline constexpr Color BACKGROUND = Color::Black;
		inline constexpr Color WALL = Color::Gray;

		inline constexpr Color SNAKE = Color::Blue;
		inline constexpr Color SNAKE_HEAD = Color::Yellow;

		inline constexpr Color FOOD = Color::Red;
	} // namespace colors

	namespace window {
		inline constexpr uint16_t WIDTH = game::NUM_TILES_X * game::TILE_SIZE;
		inline constexpr uint16_t HEIGHT = game::NUM_TILES_Y * game::TILE_SIZE;
		inline constexpr std::string_view TITLE = "Snake Game";
	} // namespace window
} // namespace snake::config
