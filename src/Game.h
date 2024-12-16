#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include <string>

class Game {
private:
    Player player;
    int current_map;
    bool is_running;
    bool show_map;

    void display_menu() const;
    void display_inventory() const;
    void map_message(int map_num) const;
    void save_game() const;
    void load_game();
    void game_loop();

public:
    Game();  // Constructor
    void start();  // Main menu and game entry point
    void new_game();
    void continue_game();
};

#endif // GAME_H
