#include <iostream>
#include "Player.h"
#include "Enemy.h"

// Constructor
Player::Player(std::string player_name) 
    : name(player_name), health(100), level(1), experience(0), inventory(), attack_power(20) {
}

// Inventory Accessor
Inventory& Player::get_inventory() {
    return inventory;
}

// Getters
std::string Player::get_name() const { return name; };

int Player::get_health() const { return health; };

int Player::get_level() const { return level; };

int Player::get_experience() const { return experience; };

// Methods

// Takes the damage from the player's health 
void Player::take_damage(int damage) {
    health -= damage;
    std::cout << name << " takes " << damage << " damage!" << std::endl;
    if (health <= 0) {
        std::cout << name << " has died." << std::endl;
    }
}

void Player::attack(Enemy& enemy) const {
    std::cout << name << " attacks " << enemy.get_name() << " for " << attack_power << " damage!" << std::endl;
    enemy.take_damage(attack_power);
}

void Player::heal(int amount) {
    std::cout << name << " heals for " << amount << " health!" << std::endl;
    health += amount;
    std::cout << name << " health now: " << health << std::endl;
    if (health > 100) health = 100; // Cap health at 100
}

void Player::gain_experience(int amount) {
    experience += amount;
    if (experience >= 100) { // Level up every 100 XP
        experience -= 100;
        level++;
    }
}

void Player::view_inventory() {
    inventory.display_inventory();
}