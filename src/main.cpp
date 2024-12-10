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
void display_use_item(Player& player);


int main() {
    std::cout << "================================================================" << std::endl;
    // Initialize player and map
    Player player("Hero");
    Map map(10, 10);
    clear_screen();
    display_welcome_message();

    bool is_running = true;
    bool show_map = false;

    while (is_running) {
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

        // Check if the input is invalid
        if (std::cin.fail()) {
            clear_screen();
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue; // Restart the loop
        }
        

        switch (choice) {
            case 1: // Display map
                clear_screen();
                show_map = !show_map;
                break;

            case 2: { // Move player
                char direction;
                std::cout << "Enter direction (w/s/a/d): ";
                std::cin >> direction;

                // Update map with the player's movement
                map.move_player(direction, player);
                // Display updated map
                // map.display_map();

                if (map.check_win(player)) {
                    display_goal_message();
                    is_running = false; // Exit the game loop
                }
                break;
            }
            case 3:
                display_inventory(player);
                break;
            case 4:
                display_use_item(player);
                continue_screen();
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

        std::cout << std::endl;
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

void display_use_item(Player& player) {
    clear_screen();
    player.view_inventory();
    std::string item_name;

    // // Ensure proper input handling before reading the item name
    std::cin.clear(); // Clear error flags
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    std::cout << "Enter the name of the item you want to use: ";
    std::cin.ignore();
    std::getline(std::cin, item_name); // Read the item name

    std::cout << "Raw input: [" << item_name << "]" << std::endl; // Debugging
    player.use_item(item_name); // Attempt to use the item

    // Additional buffer clearing to fix lingering input
    std::cin.clear(); 
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Double-check for lingering newline

    //continue_screen(); // Wait for the user to press Enter
}


// clang++ -std=c++17 src/main.cpp src/Player.cpp src/Map.cpp src/Room.cpp src/Item.cpp src/Utils.cpp src/Inventory.cpp src/Enemy.cpp -o game && ./game