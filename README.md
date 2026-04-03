# Snake Game

This is a classic Snake game implementation in C++. The project is structured to be easily understandable and extendable.

## Design Patterns

The game design incorporates several object-oriented principles. Notably, a clear separation of concerns is maintained between game logic (Core) and rendering (Render) components, suggesting a variation of the Model-View-Controller (MVC) pattern or a component-based design. An `IRenderer` interface is used, allowing for flexible rendering backends.

## Tools and Libraries

*   **CMake**: Used for project configuration and build system generation.
*   **SFML**: The Simple and Fast Multimedia Library is used for graphics rendering and user input handling.
*   **C++ Standard Library**: Utilized for fundamental data structures and algorithms.

## How to Use

To build and run this project:

1.  Ensure you have CMake and SFML installed on your system.
2.  Navigate to the project root directory in your terminal.
3.  Create a build directory and navigate into it:
    ```bash
    mkdir build
    cd build
    ```
4.  Configure the project with CMake:
    ```bash
    cmake ..
    ```
5.  Build the game:
    ```bash
    cmake --build .
    ```
6.  Run the executable:
    ```bash
    ./snake_game
    ```

## Future Updates

Expect continuous improvements and updates to various game components, including new features, new renderers, refactorings, and optimizations.
