#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <string>

class Player; // Forward declaration

class Enemy {
private:
    std::string name;
    int health;
    int attack_power;

public:
    // Constructor
    Enemy(std::string name, int health, int attack_power);

    // Getters
    std::string get_name() const;
    int get_health() const;
    int get_attack_power() const;

    // Methods
    void take_damage(int damage);
    void attack(Player& player) const;

    bool is_alive() const;
};

#endif // _ENEMY_H_