#include "Game.h"
#include "Utils.h"
#include "../assets/welcome_message.h"
#include "../assets/goal_message.h"
#include "../assets/game_over_message.h"
#include "../assets/first_map_message.h"
#include "../assets/second_map_message.h"
#include "../assets/third_map_message.h"
#include <fstream>
#include <iostream>

// Constructor
Game::Game() : player("Hero"), current_map(0), is_running(true), show_map(false) {}

// Start the game
void Game::start() {
    clear_screen();
    display_welcome_message();

    while (is_running) {
        clear_screen();
        std::cout << "==========================================================\n";
        std::cout << "|                 Welcome to the RPG Game!               |\n";
        std::cout << "==========================================================\n";
        std::cout << "| 1. New Game                                            |\n";
        std::cout << "| 2. Continue Game                                       |\n";
        std::cout << "| 3. Quit                                                |\n";
        std::cout << "==========================================================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                new_game();
                break;
            case 2:
                continue_game();
                break;
            case 3:
                is_running = false;
                std::cout << "Exiting the game. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue_screen_clear_buffer();
        }
    }
}

// Start a new game
void Game::new_game() {
    current_map = 0;
    player = Player("Hero"); // Reset player
    clear_screen();
    map_message(current_map);
    game_loop();
}

// Continue an existing game
void Game::continue_game() {
    if (!std::ifstream("savegame.txt")) {
        std::cout << "No saved game found! Starting a new game instead.\n";
        continue_screen_clear_buffer();
        new_game();
        return;
    }

    load_game();
    game_loop();
}

// Main game loop
void Game::game_loop() {
    const int total_maps = 3;

    for (; current_map < total_maps && is_running; ++current_map) {
        map_message(current_map);
        Map map(10, 10);
        bool map_complete = false;

        while (!map_complete && is_running) {
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
                map.move_player(input[0], player);

                if (map.check_win(player)) {
                    if (current_map < total_maps - 1) {
                        std::cout << "You found the exit and used the key! Map " << (current_map + 1) << " complete.\n";
                    }
                    map_complete = true;
                }
            } else if (input.size() == 1 && std::isdigit(input[0])) {
                int choice = input[0] - '0';
                switch (choice) {
                    case 1:
                        clear_screen();
                        show_map = !show_map;
                        break;
                    case 2:
                        display_inventory(player);
                        continue_screen_clear_buffer();
                        break;
                    case 3:
                        player.use_item();
                        break;
                    case 4:
                        player.view_stats();
                        break;
                    case 5:
                        save_game();
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

        if (map_complete && current_map < total_maps - 1) {
            if (player.get_inventory().remove_item("Key")) {
                std::cout << "The Key has been removed as you transition to the next map.\n";
            }
            save_game(); // Save progress after completing a map
            // continue_screen();
        }
    }

    if (is_running) {
        display_goal_message();
    }
}

// Save game progress
void Game::save_game() const {
    std::ofstream save_file("savegame.txt");
    save_file << current_map << "\n";
    player.save(save_file);
    save_file.close();
    std::cout << "Game saved successfully.\n";
    continue_screen_clear_buffer();
}

// Load saved game progress
void Game::load_game() {
    std::ifstream save_file("savegame.txt");
    save_file >> current_map;
    player.load(save_file);
    save_file.close();
    std::cout << "Game loaded successfully.\n";
    continue_screen_clear_buffer();
}

// Display map-specific messages
void Game::map_message(int map_num) const {
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

// Display the menu
void Game::display_menu() const {
    std::cout << "==========================================================\n";
    std::cout << "|                      GAME MENU                        |\n";
    std::cout << "==========================================================\n";
    std::cout << "| 1. Toggle Map                                         |\n";
    std::cout << "| 2. View Inventory                                     |\n";
    std::cout << "| 3. Use Item                                           |\n";
    std::cout << "| 4. View Player Stats                                  |\n";
    std::cout << "| 5. Save and Quit                                      |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| Use 'w', 'a', 's', or 'd' to move directly.           |\n";
    std::cout << "==========================================================\n";
    std::cout << "Enter your choice: ";
}

// Display inventory
void Game::display_inventory(Player& player) const {
    player.view_inventory();
}
