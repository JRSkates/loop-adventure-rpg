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
    bool key_placed = false; // Flag to ensure the Key is placed
    std::vector<Item> item_pool = {
        {"Healing Potion", "heal", 50},
        {"Magic Sword", "attack_boost", 20},
        {"Shield", "defence_boost", 10},
        {"Gold Coins", "currency", 100},
        {"Elixir", "heal", 100},
    };

    for (int i = 0; i < num_loot_rooms; ++i) {
        int loot_x, loot_y;
        do {
            loot_x = std::rand() % width;
            loot_y = std::rand() % height;
        } while ((loot_x == player_x && loot_y == player_y) || // Avoid starting position
                 (loot_x == goal_x && loot_y == goal_y) ||     // Avoid goal position
                 grid[loot_y][loot_x].get_type() != "empty");  // Avoid existing loot rooms

        // Assign an Item to the loot room
        Item* random_item;

        if (!key_placed) {
            // Place the Key in one of the loot rooms
            random_item = new Item("Key", "special", 0);
            key_placed = true;
        } else {
            // Assign a random item from the pool
            random_item = new Item(item_pool[std::rand() % item_pool.size()]);
        }

        grid[loot_y][loot_x].set_type("loot");
        grid[loot_y][loot_x].set_loot(random_item);
    }

    // Randomly place enemy rooms
    int num_enemy_rooms = std::rand() % 3 + 2; // Randomly choose 2-5 enemy rooms
    std::vector<Enemy> enemy_pool = {
        {"Goblin", 50, 10, 25},
        {"Troll", 75, 20, 50},
        {"Rat", 10, 2, 5},
        {"Mystery Man", 100, 50, 100}
    };


    for (int i = 0; i < num_enemy_rooms; ++i) {
        int enemy_x, enemy_y;
        do {
            enemy_x = std::rand() % width;
            enemy_y = std::rand() % height;
        } while ((enemy_x == player_x && enemy_y == player_y) || // Avoid starting position
                (enemy_x == goal_x && enemy_y == goal_y) ||     // Avoid goal position
                grid[enemy_y][enemy_x].get_type() != "empty");  // Avoid existing occupied rooms

        Enemy* random_enemy;

        random_enemy = new Enemy(enemy_pool[std::rand() % enemy_pool.size()]); // Randomly choose an enemy from the pool

        grid[enemy_y][enemy_x].set_type("enemy");
        grid[enemy_y][enemy_x].set_enemy(random_enemy); // Example enemy
    }
}


void Map::display_map() const {
    std::cout << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                       MAP VIEW                        |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    for (size_t y = 0; y < grid.size(); ++y) {
        std::cout << "| ";
        for (size_t x = 0; x < grid[y].size(); ++x) {
            if (y == static_cast<size_t>(player_y) && x == static_cast<size_t>(player_x)) {
                std::cout << 'P'; // Show player position dynamically
            } else {
                std::cout << grid[y][x].get_symbol(); // Display the room's symbol
            }
        }
        std::cout << std::string(grid[0].size() - grid[y].size(), ' ') << " |" << std::endl; // Align row
    }
    std::cout << "==========================================================" << std::endl;
    std::cout << "| Player position: (" << player_x << ", " << player_y << ")" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << std::endl;
}

void Map::move_player(char direction, Player& player) {
    // Update player position based on direction
    switch (direction) {
        case 'w': if (player_y > 0) player_y--; break;
        case 's': if (player_y < static_cast<int>(grid.size()) - 1) player_y++; break;
        case 'a': if (player_x > 0) player_x--; break;
        case 'd': if (player_x < static_cast<int>(grid.size()) - 1) player_x++; break;
        default:
            clear_screen();
            std::cout << "Invalid direction. Please try again." << std::endl;
            return;
    }

    // Interact with the room at the new player position
    grid[player_y][player_x].enter_room(player);
}


bool Map::check_win(Player& player) const {
    if (grid[player_y][player_x].get_type() == "exit") {
        return player.get_inventory().has_item("Key"); // Check if player has the Key
    }
    return false; // Not in the exit room
}