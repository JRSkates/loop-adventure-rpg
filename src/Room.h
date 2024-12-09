#ifndef _ROOM_H_
#define _ROOM_H_

#include <iostream>
#include <string>
#include <vector>

class Player; // Forward declaration to avoid circular dependency


class Room {
private:
    int x;
    int y;
    std::string type; // eg: empty, exit, loot
    std::string loot; // Loot item in the room

public:
    // Constructor
    Room(int x, int y, const std::string& type = "empty", const std::string& loot = "");


    // Getters
    int get_x() const;
    int get_y() const;
    std::string get_type() const;
    std::string get_loot() const;

    // Setters
    void set_type(const std::string &type);
    void set_loot(const std::string &loot);

    // Methods
    char get_symbol() const; // returns a character representing the room
    void enter_room(Player &player);
};

#endif // _ROOM_H_