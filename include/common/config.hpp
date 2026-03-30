#pragma once
#include <cstdint>
#include <string_view>

namespace snake::config {
	namespace window {
		inline constexpr uint16_t WIDTH = 800;
		inline constexpr uint16_t HEIGHT = 600;
		inline constexpr std::string_view TITLE = "Snake Game";
	} // namespace window
	namespace game {
		inline constexpr float TILE_SIZE = 25.0f;
		inline constexpr uint16_t INITIAL_SNAKE_LENGTH = 3;
		inline constexpr float FPS = 10.0f;
	} // namespace game
} // namespace snake::config
