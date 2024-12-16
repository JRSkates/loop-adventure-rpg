#include <iostream>
#include <fstream>
#include "Player.h"
#include "Enemy.h"
#include "Utils.h"

// Constructor
Player::Player(std::string player_name) 
    : name(player_name), health(100), level(1), experience(0), inventory(), attack_power(20), defence(0){
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

int Player::get_attack_power() const { return attack_power; };

int Player::get_defence() const { return defence; };

// Methods

// Takes the damage from the player's health 
void Player::take_damage(int damage) {
    if (defence != 0) {
        damage -= defence;
        if (damage < 0) {
            damage = 0;
        }
        std::cout << "| Defence reduces damage by " << defence << "!" << std::endl;
        std::cout << "| Reduced damage: " << damage << std::endl;
    }
    health -= damage;
    std::cout << "| " << name << " takes " << damage << " damage. Remaining health: "<< health << std::endl;
    if (health <= 0) {
        std::cout << name << " has died." << std::endl;
    }
}

void Player::attack(Enemy& enemy) const {
    std::cout << "| "<< name << " attacks " << enemy.get_name() << " for " << attack_power << " damage!" << std::endl;
    enemy.take_damage(attack_power);
    std::cout << std::endl;
}

void Player::heal(int amount) {
    std::cout << name << " heals for " << amount << " health!" << std::endl;
    health += amount;

    // Cap health at 100
    if (health > 100) {
        health = 100;
        std::cout << name << " healed to max health!: " << health << std::endl;
    } else {
        std::cout << name << " health now: " << health << std::endl;
    }
}

void Player::boost_attack(int value) {
    attack_power += value;
    std::cout << name << " boosts attack power by " << value << "!" << std::endl;
    std::cout << "attack power is now: " << attack_power << std::endl;
}

void Player::boost_defence(int value) {
    defence += value;
    std::cout << name << " boosts defence by " << value << "!" << std::endl;
    std::cout << "defence is now: " << defence << std::endl;
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

void Player::use_item() {
    clear_screen();
    inventory.display_inventory();
    std::string item_name;

    // // Ensure proper input handling before reading the item name
    std::cin.clear(); // Clear error flags
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    std::cout << "Enter the name of the item you want to use: ";
    std::cin.ignore();
    std::getline(std::cin, item_name); // Read the item name
    std::string clean_name = trim(item_name);
    if (!inventory.use_item(clean_name, *this)) {
        std::cout << "Failed to use item: " << clean_name << std::endl;
    }

    continue_screen();
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
    std::cout << "| Attack Power: " << attack_power << std::endl;
    std::cout << "| Defence: " << defence << std::endl;
    std::cout << "==========================================================" << std::endl;
    continue_screen_clear_buffer();
}

bool Player::is_dead() const {
    return health <= 0;
}

void Player::flee() {
    std::cout << name << " flees the room!" << std::endl;
}

void Player::save(std::ofstream& save_file) const {
    save_file << name << "\n"
              << health << "\n"
              << level << "\n"
              << experience << "\n"
              << attack_power << "\n";

    // Save inventory size and items
    save_file << inventory.get_size() << "\n";
    for (const auto& item : inventory.get_items()) {
        save_file << item.get_name() << "\n"
                  << item.get_effect() << "\n"
                  << item.get_value() << "\n";
    }
}

void Player::load(std::ifstream& save_file) {
    std::getline(save_file, name);
    save_file >> health >> level >> experience >> attack_power;

    // Load inventory size and items
    int inventory_size;
    save_file >> inventory_size;
    save_file.ignore(); // Ignore newline character

    inventory.clear(); // Clear any existing inventory
    for (int i = 0; i < inventory_size; ++i) {
        std::string item_name, item_effect;
        int item_value;

        std::getline(save_file, item_name);
        std::getline(save_file, item_effect);
        save_file >> item_value;
        save_file.ignore(); // Ignore newline character

        inventory.add_item(Item(item_name, item_effect, item_value));
    }
}