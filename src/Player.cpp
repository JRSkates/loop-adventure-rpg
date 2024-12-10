#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Utils.h"

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
    std::cout << "| " << name << " takes " << damage << " damage. Remaining health: "<< health << std::endl;
    if (health <= 0) {
        std::cout << name << " has died." << std::endl;
    }
}

void Player::attack(Enemy& enemy) const {
    std::cout << "| "<< name << " attacks " << enemy.get_name() << " for " << attack_power << " damage!" << std::endl;
    enemy.take_damage(attack_power);
}

void Player::heal(int amount) {
    std::cout << name << " heals for " << amount << " health!" << std::endl;
    health += amount;
    std::cout << name << " health now: " << health << std::endl;
    if (health > 100) health = 100; // Cap health at 100
}

void Player::boost_attack(int value) {
    attack_power += value;
    std::cout << name << " boosts attack power by " << value << "!" << std::endl;
    std::cout << "attack power is now: " << attack_power << std::endl;
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

void Player::view_stats() {
    clear_screen();
    std::cout << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "|                        STATS                           |" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "| Name: " << name << std::endl;
    std::cout << "| Health: " << health << "/" << 100 << std::endl;
    std::cout << "| Level: " << level << std::endl;
    std::cout << "| Experience: " << experience << "/" << 100 << std::endl;
    std::cout << "==========================================================" << std::endl;
    continue_screen();
}

bool Player::is_dead() const {
    return health <= 0;
}