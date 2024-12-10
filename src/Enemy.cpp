#include "Enemy.h"
#include "Player.h"
#include "Utils.h"
#include <iostream>

// Constructor
Enemy::Enemy(std::string name, int health, int attack_power, int experience_value)
    : name(name), health(health), attack_power(attack_power), experience_value(experience_value) {}


// Getters
std::string Enemy::get_name() const { return name; };

int Enemy::get_health() const { return health; };

int Enemy::get_attack_power() const { return attack_power; };

int Enemy::get_experience_value() const { return experience_value; };

void Enemy::take_damage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << "| You defeated the " << name << "!" << std::endl;
    } else {
        std::cout << "| "<< name << " takes " << damage << " damage. Remaining health: "<< health << std::endl;
    }
}

void Enemy::attack(Player& player) const {
    std::cout << "| "<< name << " attacks " << player.get_name() << " for " << attack_power << " damage!" << std::endl;
    player.take_damage(attack_power);
}

bool Enemy::is_alive() const { return health > 0; }