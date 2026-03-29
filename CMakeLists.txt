cmake_minimum_required(VERSION 3.10)
project(snake_game VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(
	SOURCES
	src/main.cpp
	src/core/game.cpp
	src/core/snake.cpp
	src/render/sfml_renderer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(
	${PROJECT_NAME} PRIVATE
	sfml-graphics
	sfml-window
	sfml-system
)