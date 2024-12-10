#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"
#include "Enemy.h"

class Inventory; // Forward declaration to avoid circular dependency
class Enemy; // Forward declaration to avoid circular dependency

class Player {
private:
    std::string name;
    int health;
    int level;
    int experience;
    Inventory inventory;
    int attack_power;

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
    void attack(Enemy& enemy) const;
    void heal(int amount);
    void boost_attack(int value);
    void gain_experience(int amount);

    void view_inventory();
    void view_stats();

    bool is_dead() const;
};

#endif // _PLAYER_H_