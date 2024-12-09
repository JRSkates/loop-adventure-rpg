#include "Room.h"
#include "Map.h"
#include "Player.h"
#include <iostream>
#include "Utils.h"

Room::Room(int x, int y, const std::string& type, Item* loot)
    : x(x), y(y), type(type), loot(loot) {};

Room::~Room() {
    if (loot != nullptr) {
        delete loot;
        loot = nullptr;
    }
}

int Room::get_x() const { return x; };

int Room::get_y() const { return y; };
std::string Room::get_type() const { return type; };
Item* Room::get_loot() const { return loot; };

void Room::set_type(const std::string& type) {
    this->type = type;
}

void Room::set_loot(Item* loot) {
    this->loot = loot;
}

char Room::get_symbol() const {
    if (type == "empty") return '.';
    else if (type == "start") return 'S';
    else if (type == "loot") return 'L';
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
    } else if (type == "exit") {
        std::cout << "| You found the exit! Congratulations, you win!          |" << std::endl;
    } else {
        std::cout << "| This room is empty!                                   |" << std::endl;
    }

    std::cout << "==========================================================" << std::endl;

     // Pause to allow the player to read the interaction
    continue_screen();
}




