#ifndef GOAL_MESSAGE_H
#define GOAL_MESSAGE_H

#include <iostream>

void display_goal_message() {
std::cout << R"(
---------------------------------------H----------------------------------------
                                   
                    You open the door and sunlight blinds you

                       "Okay nice one pretty quick too!"

              You drop the map on the floor and walk into the light

                               "See you soon kid"

---------------------------------------H----------------------------------------
)" << std::endl;
continue_screen();
std::cout << R"(
    
██╗   ██╗  ██████╗  ██╗   ██╗    ██╗    ██╗ ██╗ ███╗   ██╗ ██╗
╚██╗ ██╔╝ ██╔═══██╗ ██║   ██║    ██║    ██║ ██║ ████╗  ██║ ██║
 ╚████╔╝  ██║   ██║ ██║   ██║    ██║ █╗ ██║ ██║ ██╔██╗ ██║ ██║
  ╚██╔╝   ██║   ██║ ██║   ██║    ██║███╗██║ ██║ ██║╚██╗██║ ╚═╝
   ██║    ╚██████╔╝ ╚██████╔╝    ╚███╔███╔╝ ██║ ██║ ╚████║ ██╗
   ╚═╝     ╚═════╝   ╚═════╝      ╚══╝╚══╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝                                                                                                                   
-----------------------------------------------------------------  
            Congratulations! You made it out! :)                
-----------------------------------------------------------------
            But something about that felt familiar
        Had you been here before? Or maybe again later...
-----------------------------------------------------------------
)" << std::endl;
}

#endif // GOAL_MESSAGE_H
