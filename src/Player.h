#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"
#include "Enemy.h"

class Enemy; // Forward declaration to avoid circular dependency

class Player {
private:
    std::string name;
    int health;
    int level;
    int experience;
    Inventory inventory;
    int attack_power;
    int defence;

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

    int get_attack_power() const;

    int get_defence() const;

    //Methods
    void take_damage(int damage);
    void attack(Enemy& enemy) const;
    void heal(int amount);
    void boost_attack(int value);

    void boost_defence(int value);
    void gain_experience(int amount);

    void view_inventory();
    void use_item();
    void view_stats();

    bool is_dead() const;

    void flee();
};

#endif // _PLAYER_H_