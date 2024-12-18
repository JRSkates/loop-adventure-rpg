#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Room.h"
#include "Item.h"
#include "Utils.h"
#include "../assets/goal_message.h"
#include "../assets/welcome_message.h"
#include "../assets/game_over_message.h"
#include "../assets/first_map_message.h"
#include "../assets/second_map_message.h"
#include "../assets/third_map_message.h"

void player_name(Player& player);
void display_menu();
void display_inventory(Player& player);
void map_message(int map_num);

// Game Class in different branch
int main() {
    std::cout << "================================================================" << std::endl;
    const int total_maps = 3;
    clear_screen();
    display_welcome_message();

    Player player("Player");
    player_name(player);

    //std::cout << "Welcome, " << player.get_name() << "! Your adventure begins now." << std::endl;
    // clear_screen();
    //continue_screen();
  

    bool is_running = true;
    bool show_map = false;

    for (int map_count = 0; map_count < total_maps && is_running; ++map_count) {
        map_message(map_count);
        std::cout << "==========================================================\n";
        std::cout << "|                     MAP " << (map_count + 1) << " STARTED                     |\n";
        std::cout << "==========================================================\n";
        Map map(10, 10);
        bool map_complete = false;

        while (!map_complete && is_running) {
            // Check if the player is dead
            if (player.is_dead()) {
                display_game_over_message();
                is_running = false;
                break;
            }

            if (show_map) {
                map.display_map();
            }
            display_menu();

            std::string input;
            std::cin >> input;

            if (input == "w" || input == "a" || input == "s" || input == "d") {
                // Handle movement commands
                map.move_player(input[0], player);

                if (map.check_win(player)) {
                    if (map_count < total_maps - 1) {
                        std::cout << "You found the exit and used the key! Map " << (map_count + 1) << " complete.\n";
                        // continue_screen();
                    }
                    map_complete = true;
                }
            } else if (input.size() == 1 && std::isdigit(input[0])) {
                // Handle menu options
                int choice = input[0] - '0'; // Convert char to int
                switch (choice) {
                    case 1: // Toggle map
                        clear_screen();
                        show_map = !show_map;
                        break;
                    case 2:
                        display_inventory(player);
                        break;
                    case 3:
                        player.use_item();
                        break;
                    case 4:
                        player.view_stats();
                        break;
                    case 5:
                        std::cout << "Exiting the game. Goodbye!" << std::endl;
                        is_running = false;
                        break;
                    default:
                        clear_screen();
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } else {
                clear_screen();
                std::cout << "Invalid input. Please enter a valid menu option or move command.\n";
            }
        }

        if (map_complete && map_count < total_maps - 1) {
            // Remove the Key from the player's inventory
            if (player.get_inventory().remove_item("Key")) {
                std::cout << "The Key has been removed as you transition to the next map.\n";
            }

            // std::cout << "You completed Map " << (map_count + 1) << "! Get ready for the next map...\n";
            continue_screen();
        }
    }

    if (is_running) {
        display_goal_message();
    }

    return 0;
}

void player_name(Player& player) {
    clear_screen();
    std::string player_name_input;

    std::cin.clear(); // Clear error flags

    std::cout << "Enter your name: ";

    std::getline(std::cin, player_name_input); // Read the item name
    std::string clean_name = trim(player_name_input);
    player.set_name(clean_name);
    std::cout << "Welcome, " << player.get_name() << "! Your adventure begins now." << std::endl;

    continue_screen();
}

void display_menu() {
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                      GAME MENU                        |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "| 1. Toggle Map                                         |" << std::endl;
    std::cout << "| 2. View Inventory                                     |" << std::endl;
    std::cout << "| 3. Use Item                                           |" << std::endl;
    std::cout << "| 4. View Player Stats                                  |" << std::endl;
    std::cout << "| 5. Quit                                               |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "| Use 'w', 'a', 's', or 'd' to move directly.           |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Enter your choice: ";
}

void display_inventory(Player& player) {
    player.view_inventory();
    continue_screen_clear_buffer();
}

void map_message(int map_num) {
    switch (map_num) {
        case 0:
            display_first_map_message();
            break;
        case 1:
            display_second_map_message();
            break;
        case 2:
            display_third_map_message();
            break;
        default:
            std::cout << "An unknown map has been encountered." << std::endl;
    }
}


// Compile and run the game
// make - creates the game file
// ./game

// OR
// clang++ -std=c++17 src/main.cpp src/Player.cpp src/Map.cpp src/Room.cpp src/Item.cpp src/Utils.cpp src/Inventory.cpp src/Enemy.cpp -o game && ./game