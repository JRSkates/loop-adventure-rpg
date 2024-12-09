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
};

#endif // _INVENTORY_H_