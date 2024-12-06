#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <string>
#include <iostream>

class Map {
private:
    std::vector<std::vector<char>> grid;
    int player_x;
    int player_y;
    int goal_x;
    int goal_y;

public:
    // Constructor
    Map(int width, int height);

    //Methods
    void display_map() const;
    void move_player(char direction);
    bool check_win() const;
};

#endif // _MAP_H_