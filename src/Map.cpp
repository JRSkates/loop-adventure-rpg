#include <iostream>
#include "Map.h"

Map::Map(int width, int height) : player_x(0), player_y(0) {
    // initialize grid with "."
    grid = std::vector<std::vector<char>>(height, std::vector<char>(width, '.'));
    grid[player_y][player_x] = 'P';
}

void Map::display_map() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
    std::cout << "Player position: (" << player_x << ", " << player_y << ")" << std::endl;
}

void Map::move_player(char direction) {
    grid[player_y][player_x] = '.'; // Clear the current player position

    // Update player position
    switch (direction) {
        case 'w':
        case 'W':
            if (player_y > 0) player_y--; break; // Move up
        case 's':
        case 'S':
            if (player_y < grid.size() - 1) player_y++; break; // Move down
        case 'a':
        case 'A':
            if (player_x > 0) player_x--; break; // Move left
        case 'd':
        case 'D':
            if (player_x < grid[0].size() - 1) player_x++; break;
    }

    grid[player_y][player_x] = 'P'; // Place the player at the new position
}