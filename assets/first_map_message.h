#ifndef _FIRST_MAP_MESSAGE_
#define _FIRST_MAP_MESSAGE_

#include <iostream>
#include "../src/Utils.h"

void display_first_map_message() {
    std::cout << R"(
---------------------------------------H---------------------------------------- 

                     You wake up in a dark and mysterious room

                             How did you get here?
                        How long have you been sleeping?

                                 Who are you?

                    You look down at the floor and see a map

                               You hear a voice
                          "You're going to need this"

         There are doors leading out of the room, and a mark on the map 
                                at the top left
                               
            "This is where you were, well... it's where you are now."

                    One of the rooms on the map is marked 'E'

                       "E for exit right? I can't remember
                      what we decided... it's probably fine"

         "I guess I'll try and find my way out" you think to yourself...

---------------------------------------H----------------------------------------
)" << std::endl;
continue_screen();
}

#endif // _FIRST_MAP_MESSAGE_