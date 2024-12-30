---

# Plants vs. Zombies 

## Project Overview

This project is a C++ game inspired by the style of *Plants vs. Zombies* (PvZ). Players are tasked with implementing game logic and developing their own version of the game. The provided framework handles the display of image assets and user interactions via mouse and keyboard, while you focus on adding game content. The project leverages object-oriented programming (OOP) principles, abstracting all game components into manageable game objects.

---

## Features

- **Object-Oriented Architecture**: Utilize inheritance and polymorphism to define behavior for various plants, zombies, and game components.
- **Frame-by-Frame Animation**: Sprite sheets are used to optimize asset usage and performance.
- **Customizable Levels**: Design your own plants, zombies, and game logic.
- **Extensibility**: The project uses CMake as its build system, supporting cross-platform development (Windows, macOS, Linux).
- **Dynamic Game Updates**: Game logic is updated in real-time through the `Update()` method.

---

## Installation and Setup

### 1. Prerequisites

Make sure the following tools are installed:
- **CMake** (version 3.21 or later recommended)
- **Visual Studio** (Community 2022 or later recommended for Windows)
- **Xcode** (for macOS)
- **g++ or clang++** (for Linux)

### 2. Download and Setup

1. Clone the project repository to your local machine:
   ```bash
   git clone <repository_url>
   cd <project_directory>
   ```

2. Configure with CMake:
   - **Windows**:
     Use `cmake-gui` to load the project and select `Visual Studio` as the generator.
   - **macOS/Linux**:
     Run the following commands:
     ```bash
     mkdir build && cd build
     cmake ..
     ```

3. Build the project:
   - **Windows**:
     Open the generated `*.sln` file in Visual Studio, set `PvZ` as the startup project, and press `Ctrl+F5` to run.
   - **macOS/Linux**:
     Run the following commands in the `build` directory:
     ```bash
     make -j
     ./bin/PvZ
     ```

---

## Development Guide

### Project Structure

- **GameWorld**: The main game world class that manages all game objects (plants, zombies, etc.).
- **GameObject**: The base class for all game components.
- **Plants & Zombies**: Specific plant and zombie classes that inherit from `GameObject` to define unique behaviors.
- **Assets**: Contains sprite sheets and other resource files.
- **Framework**: Framework code that provides low-level support such as rendering and event handling.

### Key Implementations

1. **Custom Plants and Zombies**:
   - Create classes inheriting from `GameObject`.
   - Implement the `Update()` method to define behavior.
   - Add objects to the `GameWorld` management container.

2. **Event Handling**:
   - Use the `OnClick()` method to handle player click events.
   - Safely manage objects in the game world using `shared_from_this()`.

3. **Game Logic**:
   - Use `Init()` to initialize levels.
   - Update game logic every frame using `Update()`, such as spawning sunlight, moving zombies, and triggering attacks.
   - Clean up level data and objects using `CleanUp()`.


---

## License

The image and animation assets in this project are sourced from *Plants vs. Zombies* and are copyrighted by PopCap Games. The code is released under the MIT License.

---
