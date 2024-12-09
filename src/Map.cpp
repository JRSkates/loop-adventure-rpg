#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "Map.h"

Map::Map(int width, int height) : player_x(0), player_y(0) {
    std::srand(std::time(0)); // Seed for random number generation

    // Randomize goal position
    do {
        goal_x = std::rand() % width;
        goal_y = std::rand() % height;
    } while (goal_x == player_x && goal_y == player_y);

    // Initialize grid with Room objects
    for (int y = 0; y < height; ++y) {
        std::vector<Room> row;
        for (int x = 0; x < width; ++x) {
            // Create a Room at (x, y) and add it to the row
            if (x == goal_x && y == goal_y) {
                row.emplace_back(x, y, "exit"); // Exit room
            } else if (x == 2 && y == 3) {
                row.emplace_back(x, y, "loot", "Healing Potion"); // Loot room
            } else if (x == 5 && y == 7) {
                row.emplace_back(x, y, "loot", "Magic Sword"); // Loot room
            } else {
                row.emplace_back(x, y, "empty"); // Default empty room
            }
        }
        grid.push_back(row); // Add the row to the grid
    }

    // Initialize the starting room as the player's position
}


void Map::display_map() const {
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            if (y == player_y && x == player_x) {
                std::cout << 'P'; // Show player position dynamically
            } else {
                std::cout << grid[y][x].get_symbol(); // Display the room's symbol
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Player position: (" << player_x << ", " << player_y << ")" << std::endl;
}

void Map::move_player(char direction, Player& player) {
    // Update player position based on direction
    switch (direction) {
        case 'w': if (player_y > 0) player_y--; break;
        case 's': if (player_y < grid.size() - 1) player_y++; break;
        case 'a': if (player_x > 0) player_x--; break;
        case 'd': if (player_x < grid[0].size() - 1) player_x++; break;
        default:
            std::cout << "Invalid direction. Please try again." << std::endl;
            return;
    }

    // Interact with the room at the new player position
    grid[player_y][player_x].enter_room(player);
}


bool Map::check_win() const {
    return grid[player_y][player_x].get_type() == "exit";
}