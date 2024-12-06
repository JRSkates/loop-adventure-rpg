#include <iostream>
#include "Player.h"
#include "Map.h"

void display_menu() {
    std::cout << "1. Display Map" << std::endl;
    std::cout << "2. Move Player" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::cout << "================================================================" << std::endl;
    // Initialize player and map
    Player player("Hero");
    Map map(10, 10);

    bool is_running = true;

    while (is_running) {
        display_menu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: // Display map
                map.display_map();
                break;

            case 2: { // Move player
                char direction;
                std::cout << "Enter direction (w/s/a/d): ";
                std::cin >> direction;

                // Update map with the player's movement
                map.move_player(direction);

                // Display updated map
                map.display_map();
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

// clang++ -std=c++17 src/main.cpp src/Player.cpp src/Map.cpp -o game && ./game