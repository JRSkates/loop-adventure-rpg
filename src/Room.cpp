#include "Room.h"
#include "Player.h"
#include <iostream>

Room::Room(int x, int y, const std::string& type, const std::string& loot)
    : x(x), y(y), type(type), loot(loot) {};

int Room::get_x() const { return x; };

int Room::get_y() const { return y; };
std::string Room::get_type() const { return type; };
std::string Room::get_loot() const { return loot; };

void Room::set_type(const std::string& type) {
    this->type = type;
}

void Room::set_loot(const std::string& loot) {
    this->loot = loot;
}

char Room::get_symbol() const {
    if (type == "empty") return '.';
    else if (type == "start") return 'S';
    else if (type == "loot") return 'L';
    else if (type == "exit") return 'E';
    else return '?';
}

void Room::enter_room(Player& player) {
    // std::cout << "DEBUG: Room at (" << x << ", " << y << ") entered." << std::endl;
    // std::cout << "DEBUG: Room type before interaction: " << type << std::endl;

    if (type == "exit") {
        std::cout << "You found the exit! Congratulations, you win!" << std::endl;
    } else if (type == "loot") {
        std::cout << "You find " << loot << "!" << std::endl;
        // if (player.get_inventory().add_item(loot)) {
        //     loot = ""; // Remove loot after adding it to inventory
        //     type = "empty"; // Mark the room as empty
        // }
    } else {
        std::cout << "This room is empty!" << std::endl;
    }

   //  std::cout << "DEBUG: Room type after interaction: " << type << std::endl;
}

