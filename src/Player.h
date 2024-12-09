#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"

class Player {
private:
    std::string name;
    int health;
    int level;
    int experience;
    Inventory inventory;

public:
    // Constructor
    Player(std::string name);

    // Inventory Accessor
    Inventory& get_inventory();

    // Getters
    std::string get_name() const;
    int get_health() const;
    int get_level() const;
    int get_experience() const;

    //Methods
    void take_damage(int damage);
    void heal(int amount);
    void gain_experience(int amount);

    void view_inventory();
};

#endif // _PLAYER_H_