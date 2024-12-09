#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

class Inventory {
private:
    std::vector<Item> items;

public:
    // Constructor
    Inventory(std::vector<Item> items = {});
    // Getters
    int get_size() const;

    // Methods
    void add_item(const Item& item);
    void remove_item(int index);
    void display_inventory() const;

    bool has_item(const std::string& item_name) const; // General-purpose method to check for any item
    bool has_key() const; // Specific method to check for the Key


};

#endif // _INVENTORY_H_