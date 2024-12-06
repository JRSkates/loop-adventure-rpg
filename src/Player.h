#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <vector>
#include <string>

class Player {
private:
    std::string name;
    int health;
    int level;
    int experience;

public:
    // Constructor
    Player(std::string name);

    // Getters
    std::string get_name() const;
    int get_health() const;
    int get_level() const;
    int get_experience() const;

    //Methods
    void take_damage(int damage);
    void heal(int amount);
    void gain_experience(int amount);
};

#endif // _PLAYER_H_