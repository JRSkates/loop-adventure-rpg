#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <string>
#include <iostream>
#include "Room.h"

class Player; // Forward declaration of Player

class Map {
private:
    std::vector<std::vector<Room>> grid;
    int player_x;
    int player_y;
    int goal_x;
    int goal_y;

public:
    // Constructor
    Map(int width, int height);

    //Methods
    void display_map() const;
    void move_player(char direction, Player& player);
    bool check_win(Player& player) const;

};

#endif // _MAP_H_