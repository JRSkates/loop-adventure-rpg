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

