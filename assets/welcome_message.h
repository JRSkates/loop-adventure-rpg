#ifndef WELCOME_MESSAGE_H
#define WELCOME_MESSAGE_H

#include <iostream>

void display_welcome_message() {
    std::cout << R"(

     ██╗          ██████╗      ██████╗     ██████╗     ██╗
     ██║         ██╔═══██╗    ██╔═══██╗    ██╔══██╗    ██║
     ██║         ██║   ██║    ██║   ██║    ██████╔╝    ██║
     ██║         ██║   ██║    ██║   ██║    ██╔═══╝     ╚═╝
     ███████╗    ╚██████╔╝    ╚██████╔╝    ██║         ██╗
     ╚══════╝     ╚═════╝      ╚═════╝     ╚═╝         ╚═╝

--------------------------------------------------------------
            WELCOME TO THE LOOP ADVENTURE RPG GAME
--------------------------------------------------------------
       Explore the map, battle enemies, and collect loot!
      Choose wisely, for every decision shapes your fate.
--------------------------------------------------------------
)" << std::endl;
continue_screen();
}

#endif // WELCOME_MESSAGE_H
