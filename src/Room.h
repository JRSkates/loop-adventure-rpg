#ifndef _ROOM_H_
#define _ROOM_H_

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Player.h"
#include "Enemy.h"


class Map; // Forward declaration to avoid circular dependency


class Room {
private:
    int x;
    int y;
    std::string type; // eg: empty, exit, loot
    Item* loot; // Pointer to an Item object (nullptr if no item)
    Enemy* enemy; // Pointer to an Enemy object (nullptr if no enemy)

public:
    // Constructor
    Room(int x, int y, const std::string& type = "empty", Item* loot = nullptr, Enemy* enemy = nullptr);

    ~Room();

    // Getters
    int get_x() const;
    int get_y() const;
    std::string get_type() const;
    Item* get_loot() const;
    Enemy* get_enemy() const;

    // Setters
    void set_type(const std::string &type);
    void set_loot(Item* loot);

    void set_enemy(Enemy* enemy);

    // Methods
    char get_symbol() const; // returns a character representing the room
    void enter_room(Player &player, const Map &map);
};

#endif // _ROOM_H_