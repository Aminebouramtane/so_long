# Project `so_long`

## Description
This project is part of the 1337 curriculum, aiming to create a simple 2D game called `so_long`. The game involves a player character navigating through a map, collecting items, and reaching the exit while avoiding obstacles.

## Features
- **Map Parsing**: Parses a map file that represents the game level.
- **Graphics Rendering**: Utilizes the `minilibx` library for simple graphics rendering.
- **Player Movement**: Allows the player character to move within the map boundaries.
- **Collectibles**: Implements collectible items that the player can gather for points.
- **Exit**: Marks an exit tile on the map where the player can finish the level.
- **Obstacles**: Includes obstacles such as walls and enemies that the player must avoid.

## Requirements
- C Compiler (gcc/clang recommended)
- `minilibx` library (provided by 42)

## Installation
1. Clone the repository:
  -`git clone [repository_url]`
  -`cd so_long`
2. Compile the project:
   `make` for Mandatory part and `make bonus` for bonus part
3. Run the game:
   ```./so_long [map_file]```

## Usage
- Use the arrow keys (WASD) to move the player character (up, down, left, right).
- Collect items to increase your score.
- Reach the exit to complete the level.
- Avoid obstacles and enemies.

## Example Map Format
1111111111<br>
1E01000C01<br>
1010000111<br>
1P00100X01<br>
1111111111<br>

- `1`: Wall
- `0`: Empty tile
- `P`: Player character
- `C`: Collectible item
- `E`: Exit tile

## Credits
- This project was completed as part of the 42 curriculum.
- Created by AmineBOURAMTANE ([GitHub Profile](https://github.com/Aminebouramtane))

