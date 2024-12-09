#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Room.h"
#include "Item.h"
#include "../assets/goal_message.h"
#include "../assets/welcome_message.h"

void display_menu() {
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                      GAME MENU                        |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "| 1. Display Map                                        |" << std::endl;
    std::cout << "| 2. Move Player                                        |" << std::endl;
    std::cout << "| 3. Quit                                               |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::cout << "================================================================" << std::endl;
    // Initialize player and map
    Player player("Hero");
    Map map(10, 10);

    display_welcome_message();

    bool is_running = true;

    while (is_running) {
        display_menu();

        int choice;
        std::cin >> choice;

        // Check if the input is invalid
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
            continue; // Restart the loop
        }

        switch (choice) {
            case 1: // Display map
                map.display_map();
                break;

            case 2: { // Move player
                char direction;
                std::cout << "Enter direction (w/s/a/d): ";
                std::cin >> direction;

                // Update map with the player's movement
                map.move_player(direction, player);
                // Display updated map
                // map.display_map();

                if (map.check_win()) {
                    display_goal_message();
                    is_running = false; // Exit the game loop
                }
                break;
            }
            case 3:
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

// clang++ -std=c++17 src/main.cpp src/Player.cpp src/Map.cpp src/Room.cpp src/Item.cpp src/Utils.cpp -o game && ./game