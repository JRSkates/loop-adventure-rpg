#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Room.h"
#include "Item.h"
#include "Utils.h"
#include "../assets/goal_message.h"
#include "../assets/welcome_message.h"
#include "../assets/game_over_message.h"

void display_menu();
void display_inventory(Player& player);
// void display_use_item(Player& player);


int main() {
    std::cout << "================================================================" << std::endl;
    // Initialize player and map
    const int total_maps = 3;
    Player player("Hero");
    clear_screen();
    display_welcome_message();

    bool is_running = true;
    bool show_map = false;
    
    for (int map_count = 0; map_count < total_maps && is_running; ++map_count) {
        std::cout << "==========================================================\n";
        std::cout << "|                     MAP " << (map_count + 1) << " STARTED                     |\n";
        std::cout << "==========================================================\n";
        Map map(10, 10);
        bool map_complete = false;

        while (!map_complete && is_running) {
            // Check if the player is dead before continuing the game loop
            if (player.is_dead()) {
                display_game_over_message();
                is_running = false; // Exit the game loop
                break;
            }

            if (show_map) {
                map.display_map();
            }
            // Display menu
            display_menu();

            int choice;
            std::cin >> choice;

            if (std::cin.fail()) {
                clear_screen();
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
                continue;
            }

            switch (choice) {
                case 1: // Toggle map
                    clear_screen();
                    show_map = !show_map;
                    break;

                case 2: { // Move player
                    char direction;
                    std::cout << "Enter direction (w/s/a/d): ";
                    std::cin >> direction;
                    map.move_player(direction, player);

                    if (map.check_win(player)) {
                        if (map_count < total_maps - 1) {
                            std::cout << "You found the exit and used the key! Map " << (map_count + 1) << " complete.\n";
                            // continue_screen();
                        }
                        map_complete = true;
                    }
                    break;
                }
                case 3:
                    display_inventory(player);
                    break;
                case 4:
                    player.use_item();
                    break;
                case 5:
                    player.view_stats();
                    break;
                case 6:
                    std::cout << "Exiting the game. Goodbye!" << std::endl;
                    is_running = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }

        if (map_complete && map_count < total_maps - 1) {
            std::cout << "You completed Map " << (map_count + 1) << "! Get ready for the next map...\n";
            continue_screen();
        }
    }

    // Display goal message only after completing all maps
    if (!is_running) {
        std::cout << "Game over. Thanks for playing!\n";
    } else {
        display_goal_message(); // Show the message after the final map
    }

    return 0;
}

void display_menu() {
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                      GAME MENU                        |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "| 1. Toggle Map        TEST                                 |" << std::endl;
    std::cout << "| 2. Move Player                                        |" << std::endl;
    std::cout << "| 3. View Inventory                                     |" << std::endl;
    std::cout << "| 4. Use Item                                           |" << std::endl;
    std::cout << "| 5. View Player Stats                                  |" << std::endl;
    std::cout << "| 6. Quit                                               |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Enter your choice: ";
}

void display_inventory(Player& player) {
    player.view_inventory();
    continue_screen();
}

 //void display_use_item(Player& player) {
    // clear_screen();
    // player.view_inventory();
    // std::string item_name;

    // // // Ensure proper input handling before reading the item name
    // std::cin.clear(); // Clear error flags
    // // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    // std::cout << "Enter the name of the item you want to use: ";
    // std::cin.ignore();
    // std::getline(std::cin, item_name); // Read the item name

    //std::cout << "Raw input: [" << item_name << "]" << std::endl; // Debugging
    //player.use_item(item_name); // Attempt to use the item

    // Additional buffer clearing to fix lingering input
    // std::cin.clear(); 
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Double-check for lingering newline

    //continue_screen(); // Wait for the user to press Enter
// }

// make - creates the game file
// ./game

// clang++ -std=c++17 src/main.cpp src/Player.cpp src/Map.cpp src/Room.cpp src/Item.cpp src/Utils.cpp src/Inventory.cpp src/Enemy.cpp -o game && ./game