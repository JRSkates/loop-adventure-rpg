#ifndef _THIRD_MAP_MESSAGE_
#define _THIRD_MAP_MESSAGE_

#include <iostream>
#include "../src/Utils.h"

void display_third_map_message() {
std::cout << R"(
---------------------------------------H----------------------------------------
                                   
                    You walk into a dark and mysterious room

                 "Right THREE layers, I'm making a note of that"

                          The room looks very familiar

                          "Okay, THIS one is the exit 
                    "3 layers, surely can't be more than that"

                         You see a new map on the floor

                      "Make sure you leave the old map too"

                "Guess I better find the exit" you predictably say

---------------------------------------H----------------------------------------
)" << std::endl;
continue_screen();
}

#endif // _THIRD_MAP_MESSAGE_