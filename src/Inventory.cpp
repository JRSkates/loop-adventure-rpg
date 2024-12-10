#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "Utils.h"

Inventory::Inventory(std::vector<Item> items) 
    : items(items) {  
};

// Getters
int Inventory::get_size() const { 
    return items.size(); 
};

void Inventory::add_item(const Item& item) {
    items.push_back(item);
}

void Inventory::remove_item(int index) {
    for(auto& item : items) {
        if(item.get_name() == items[index].get_name()) {
            items.erase(items.begin() + index);
            return;
        }
    }
}

void Inventory::display_inventory() const {
    clear_screen();
    std::cout << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                        INVENTORY                       |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    if(items.size() == 0) {
        std::cout << "No Items In Inventory" << std::endl;
    } else {
        for(const auto& item : items) {
            item.display();
        }
        std::cout << std::endl;
    }

    std::cout << "==========================================================" << std::endl;

    continue_screen();
}


bool Inventory::has_item(const std::string& item_name) const {
    for (const auto& item : items) {
        if (item.get_name() == item_name) {
            return true; // Item found
        }
    }
    return false; // Item not found
}

bool Inventory::has_key() const {
    return has_item("Key"); // Reuse the has_item method
}

bool Inventory::use_item(const std::string& item_name, Player& player) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->get_name() == item_name) {
            const std::string& effect = it->get_effect();
            int value = it->get_value();

            // Apply the item's effect to the player
            if (effect == "heal") {
                player.heal(value);
            } else if (effect == "attack_boost") {
                player.boost_attack(value);
            } else if (effect == "special") {
                std::cout << "You used a special item: " << item_name << "!" << std::endl;
            }

            // Remove the used item from inventory
            items.erase(it); // Erase the item at this iterator
            return true; // Item successfully used
        }
    }
    std::cout << "Item not found in inventory!" << std::endl;
    return false; // Item not found
}

