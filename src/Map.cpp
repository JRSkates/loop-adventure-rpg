#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "Map.h"
#include "Utils.h"
#include "Player.h"

Map::Map(int width, int height) : player_x(0), player_y(0) {
    std::srand(std::time(0)); // Seed for random number generation

    // Randomize goal position
    do {
        goal_x = std::rand() % width;
        goal_y = std::rand() % height;
    } while (goal_x == player_x && goal_y == player_y);

    // Initialize grid with empty rooms
    for (int y = 0; y < height; ++y) {
        std::vector<Room> row;
        for (int x = 0; x < width; ++x) {
            row.emplace_back(x, y);
        }
        grid.push_back(row);
    }

    // Mark the goal room as "exit"
    grid[goal_y][goal_x].set_type("exit");

    // Randomly place loot rooms
    int num_loot_rooms = std::rand() % 5 + 3; // Randomly choose 3-7 loot rooms
    for (int i = 0; i < num_loot_rooms; ++i) {
        int loot_x, loot_y;
        do {
            loot_x = std::rand() % width;
            loot_y = std::rand() % height;
        } while ((loot_x == player_x && loot_y == player_y) || // Avoid starting position
                 (loot_x == goal_x && loot_y == goal_y) ||     // Avoid goal position
                 grid[loot_y][loot_x].get_type() != "empty");  // Avoid existing loot rooms

        // Assign a random Item to the loot room
        std::vector<Item> item_pool = {
            {"Healing Potion", "heal", 50},
            {"Magic Sword", "attack_boost", 20},
            {"Shield", "defense_boost", 15},
            {"Gold Coins", "currency", 100},
            {"Elixir", "heal", 100},
        };
        Item* random_item = new Item(item_pool[std::rand() % item_pool.size()]);
        grid[loot_y][loot_x].set_type("loot");
        grid[loot_y][loot_x].set_loot(random_item);
    }
}


void Map::display_map() const {
    std::cout << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                       MAP VIEW                        |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    for (int y = 0; y < grid.size(); ++y) {
        std::cout << "| ";
        for (int x = 0; x < grid[y].size(); ++x) {
            if (y == player_y && x == player_x) {
                std::cout << 'P'; // Show player position dynamically
            } else {
                std::cout << grid[y][x].get_symbol(); // Display the room's symbol
            }
        }
        std::cout << std::string(grid[0].size() - grid[y].size(), ' ') << " |" << std::endl; // Align row
    }
    std::cout << "==========================================================" << std::endl;
    std::cout << "| Player position: (" << player_x << ", " << player_y << ")                    |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::endl;
}

void Map::move_player(char direction, Player& player) {
    // Update player position based on direction
    switch (direction) {
        case 'w': if (player_y > 0) player_y--; break;
        case 's': if (player_y < grid.size() - 1) player_y++; break;
        case 'a': if (player_x > 0) player_x--; break;
        case 'd': if (player_x < grid[0].size() - 1) player_x++; break;
        default:
            clear_screen();
            std::cout << "Invalid direction. Please try again." << std::endl;
            return;
    }

    // Interact with the room at the new player position
    grid[player_y][player_x].enter_room(player, *this);
}


bool Map::check_win() const {
    return grid[player_y][player_x].get_type() == "exit";
}