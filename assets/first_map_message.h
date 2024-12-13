#ifndef _FIRST_MAP_MESSAGE_
#define _FIRST_MAP_MESSAGE_

#include <iostream>
#include "../src/Utils.h"

void display_first_map_message() {
    std::cout << R"(
 ------------------------------------------------------------------------------
 
                     You wake up in a dark and mysterious room
                              How did you get here?
                          How long have you been sleeping?
                                  Who are you?

                      You look down at the floor and see a map
                      There are doors on every side of the room

             "I guess I'll try and find my way out" you think to yourself...

-------------------------------------------------------------------------------
)" << std::endl;
continue_screen();
}

#endif // _FIRST_MAP_MESSAGE_