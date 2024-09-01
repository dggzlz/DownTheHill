# Down the Hill

## Project Overview
**Down the Hill** is a video game project developed as part of COMP 2659 - Machinery II, Section 001, under the supervision of Instructor Paul Pospisil. The game simulates a downhill skiing experience with various gameplay mechanics including player movement, collision detection, scoring, and sound effects.

## Features
- **Player Movement**: Control the snowboarder using keyboard inputs to navigate left or right.
- **Collision Detection**: The game includes collision mechanics with trees and other skiers, affecting the player's score and lives.
- **Score and Lives Tracking**: Tracks the player’s score and remaining lives throughout the game.
- **Sound Effects and Music**: Includes custom sound effects and background music inspired by tracks like "Jump" by Van Halen and "Reptilia" by The Strokes.

## File Structure
- `dth.c`: Contains the main game loop and core logic for "Down the Hill".
- `effects.c`: Implements the sound effects used in the game.
- `events.c`: Handles both synchronous and asynchronous events within the game.
- `input.c`: Manages keyboard input and interaction with the game.
- `model.c`: Defines the game’s model, including the initialization and state management of game objects.
- `music.c`: Handles the background music for the game.
- `Makefile`: Script for compiling the project and generating the executable.

## Compilation
To compile the project, use the following command:

make

This will generate the `DownHill.tos` executable file.

## How to Play
- **Controls**:
  - Use the **left arrow key** (`←`) to move left.
  - Use the **right arrow key** (`→`) to move right.
  - Press **SPACE** to start the game or respawn after game over.
  - Press **ESC** to exit the game.
  
- **Objective**: Avoid obstacles and hit skiers to earn more, the longer you play, the more points you collect. The game ends when the player loses all lives.

## Authors
- Juan Diego Serrato
- Diego Gonzalez
- Course: COMP 2659
- Instructor: Paul Pospisil

## License

This project is for educational purposes under the supervision of the instructor Paul Pospisil as part of COMP 2659 at Mount Royal University.


