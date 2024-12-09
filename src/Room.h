#ifndef _ROOM_H_
#define _ROOM_H_

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Player.h"

class Map; // Forward declaration to avoid circular dependency


class Room {
private:
    int x;
    int y;
    std::string type; // eg: empty, exit, loot
    Item* loot; // Pointer to an Item object (nullptr if no item)

public:
    // Constructor
    Room(int x, int y, const std::string& type = "empty", Item* loot = nullptr);

    ~Room();

    // Getters
    int get_x() const;
    int get_y() const;
    std::string get_type() const;
    Item* get_loot() const;

    // Setters
    void set_type(const std::string &type);
    void set_loot(Item* loot);

    // Methods
    char get_symbol() const; // returns a character representing the room
    void enter_room(Player &player, const Map &map);
    void continue_map(const Map& map);
};

#endif // _ROOM_H_