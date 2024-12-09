#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    std::string effect; // Effect type, e.g., "heal", "boost"
    int value;          // Effect value, e.g., 50 HP

public:
    // Constructor
    Item(const std::string& name, const std::string& effect, int value);

    // Getters
    std::string get_name() const;
    std::string get_effect() const;
    int get_value() const;

    // Display item information
    void display() const;
};

#endif // ITEM_H
