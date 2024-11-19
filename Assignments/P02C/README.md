# Knucklebones Game

### Author: Cooper Ricketts

### Description
This project is a terminal-based recreation of the Knucklebones game using the `ncurses` library (or its Windows-compatible alternative, `pdcurses`). Players roll dice and strategically place values on a grid to maximize their score and compete with their opponent. The game includes interactive features such as clickable buttons, animated dice rolls, and grid-based gameplay.

---

### Files

|   #   | File                  | Description                                                   |
| :---: | --------------------- | ------------------------------------------------------------- |
|   1   | [game.cpp](./game.cpp) | Main driver for the game. Handles game initialization, loop, and logic. |
|   2   | [button_class.hpp](./button_class.hpp) | Defines the `Button` class for creating and managing clickable UI buttons. |
|   3   | [color_class.hpp](./color_class.hpp) | Sets up colors and color pairs for `ncurses` display.               |
|   4   | [dice_class.hpp](./dice_class.hpp)   | Implements the `DiceViz` class for visualizing dice rolls.          |
|   5   | [grid_class.hpp](./grid_class.hpp)   | Implements the `Grid` class to manage the game board.              |
|   6   | [input_class.hpp](./input_class.hpp) | (Optional) Placeholder for additional input-handling utilities.     |
|   7   | [logger_class.hpp](./logger_class.hpp) | Provides a logging utility to track events during the game.         |

---

### Instructions

1. **System Requirements**:
   - **Windows**: Install [MinGW-w64](https://sourceforge.net/projects/mingw-w64/) for `g++`.
   - **Linux/MacOS**: Use the system's package manager to install `gcc`/`g++` and `ncurses`.
   - Ensure the required headers and libraries for `ncurses` (or `pdcurses` on Windows) are installed.

2. **Setup**:
   - Navigate to the directory containing the source files:
     ```bash
     cd C:\Users\rcric\source\repos\Knucklebones_maybeactually\Knucklebones_maybeactually
     ```

3. **Compile**:
   - On **Windows** with `pdcurses`:
     ```bash
     g++ -o knucklebones game.cpp -lpdcurses
     ```
   - On **Linux/MacOS** with `ncurses`:
     ```bash
     g++ -o knucklebones game.cpp -lncurses
     ```

4. **Run the Game**:
   - Execute the program:
     ```bash
     ./knucklebones
     ```

5. **Gameplay**:
   - Use the mouse to click the "ROLL" button to roll a die.
   - Click on the grid to place the die value in a cell.
   - Press `q` to quit the game.

