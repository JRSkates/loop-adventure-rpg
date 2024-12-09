#include "Item.h"
#include <iostream>

// Constructor
Item::Item(const std::string& name, const std::string& effect, int value)
    : name(name), effect(effect), value(value) {}

// Getters
std::string Item::get_name() const { return name; }
std::string Item::get_effect() const { return effect; }
int Item::get_value() const { return value; }

// Display item details
void Item::display() const {
    std::cout << "| Item: " << name << ", Effect: " << effect << ", Value: " << value << std::endl;
}
