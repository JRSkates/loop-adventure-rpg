#ifndef _SECOND_MAP_MESSAGE_
#define _SECOND_MAP_MESSAGE_

#include <iostream>
#include "../src/Utils.h"

void display_second_map_message() {
    std::cout << R"(
---------------------------------------H----------------------------------------
                                   
                    You walk into a dark and mysterious room

                   "Okay I probably should have mentioned this"
                         "2 rooms, that was it I think"

                         You see a new map on the floor

-------------------------------------------------------------------------------
)" << std::endl;
continue_screen();
}

#endif // _SECOND_MAP_MESSAGE_