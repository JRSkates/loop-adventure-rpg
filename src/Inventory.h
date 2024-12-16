#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"


class Item; // Forward declaration to avoid circular dependency
class Player; // Forward declaration to avoid circular dependency

class Inventory {
private:
    std::vector<Item> items;

public:
    // Constructor
    Inventory(std::vector<Item> items = {});
    // Getters
    int get_size() const;
    const std::vector<Item>& get_items() const; // Return a reference to the items


    // Methods
    void add_item(const Item& item);
    bool remove_item(const std::string& item_name);
    void display_inventory() const;

    bool has_item(const std::string& item_name) const; // General-purpose method to check for any item
    bool has_key() const; // Specific method to check for the Key

    bool use_item(const std::string& item_name, Player& player);

    void clear(); 

};

#endif // _INVENTORY_H_