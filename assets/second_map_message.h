#ifndef _SECOND_MAP_MESSAGE_
#define _SECOND_MAP_MESSAGE_

#include <iostream>
#include "../src/Utils.h"

void display_second_map_message() {
std::cout << R"(
---------------------------------------H----------------------------------------
                                   
                    You walk into a dark and mysterious room

                   "Okay I probably should have mentioned this"

                          The room looks very familiar

                          "Okay, THIS one is the exit 
                         "2 layers, that was it I think"

                         You see a new map on the floor

                      "Make sure you leave the old map too"

                     "Guess I better find the exit" you say

---------------------------------------H----------------------------------------
)" << std::endl;
continue_screen();
}

#endif // _SECOND_MAP_MESSAGE_