#include <iostream>
#include "Player.h"

int main() {
    std::cout << "================================================================" << std::endl;
    Player player("John Doe");

    std::cout << "Player Name: " << player.get_name() << std::endl;
    std::cout << "Player Health: " << player.get_health() << std::endl;

    player.take_damage(20);
    player.take_damage(20);

    player.heal(20);
    
    return 0;
}

// clang++ -std=c++17 src/main.cpp src/Player.cpp src/Map.cpp -o game && ./game