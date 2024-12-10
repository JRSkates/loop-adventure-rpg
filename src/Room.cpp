#include "Room.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include "Utils.h"

Room::Room(int x, int y, const std::string& type, Item* loot, Enemy* enemy)
    : x(x), y(y), type(type), loot(loot), enemy(enemy){};

Room::~Room() {
    if (loot != nullptr) {
        delete loot;
        loot = nullptr;
    }
    if (enemy != nullptr) {
        delete enemy;
        enemy = nullptr;
    }
}

int Room::get_x() const { return x; };

int Room::get_y() const { return y; };
std::string Room::get_type() const { return type; };
Item* Room::get_loot() const { return loot; };

Enemy* Room::get_enemy() const { return enemy; };

void Room::set_type(const std::string& type) {
    this->type = type;
}

void Room::set_loot(Item* loot) {
    this->loot = loot;
}

void Room::set_enemy(Enemy* enemy) {
    this->enemy = enemy;
}

char Room::get_symbol() const {
    if (type == "empty") return '.';
    else if (type == "start") return 'S';
    else if (type == "loot") return 'L';
    else if (type == "enemy") return '!';
    else if (type == "exit") return 'E';
    else return '?';
}

// Update `enter_room` to handle `Item`
void Room::enter_room(Player& player, const Map& map) {
    clear_screen();
    std::cout << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                    ROOM INTERACTION                   |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "| You entered a room at (" << x << ", " << y << ").                         " << std::endl;

    if (type == "loot" && loot != nullptr) {
        std::cout << "| You find an item: " << loot->get_name() << "!" << std::endl;
        loot->display(); // Display item details

        player.get_inventory().add_item(*loot);
        std::cout << "| " << loot->get_name() << " has been added to your Inventory!" << std::endl;

        type = "empty"; // Mark room as empty after interacting
    } else if (type == "enemy" && enemy != nullptr) {
        std::cout << "| An enemy, " << enemy->get_name() << ", appears!" << std::endl;

        // Start combat
        while (enemy->is_alive() && player.get_health() > 0) {
            std::cout << std::endl;
            std::cout << "| 1. Attack the enemy" << std::endl;
            std::cout << "| 2. Run away" << std::endl;
            std::cout << "Enter your choice: ";
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                player.attack(*enemy); // Player's attack damage (example)
                if (enemy->is_alive()) {
                    enemy->attack(player);
                }
            } else if (choice == 2) {
                std::cout << "You fled the room!" << std::endl;
                return;
            } else {
                std::cout << "Invalid choice. Try again." << std::endl;
            }
        }

        if (!enemy->is_alive()) {
            player.gain_experience(enemy->get_experience_value());
            type = "empty"; // Room becomes empty after enemy is defeated
        }
    } else if (type == "exit") {
        if (player.get_inventory().has_item("Key")) {
            std::cout << "| You found the exit and used the Key to escape!         |" << std::endl;
        } else {
            std::cout << "| The exit is locked! You need a Key to escape.          |" << std::endl;
        }
    } else {
        std::cout << "| This room is empty!                                   |" << std::endl;
    }

    std::cout << "==========================================================" << std::endl;

     // Pause to allow the player to read the interaction
    continue_screen();
}




