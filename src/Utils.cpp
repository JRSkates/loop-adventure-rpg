#include "Utils.h"

void clear_screen() {
    std::cout << "\033[2J\033[H"; // Clear screen and move cursor to the top
}
void continue_screen() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(); // Wait for the player to press Enter
    std::cin.get();    // For clean handling of input buffer

    // Immediately display the updated map
    clear_screen();
    // map.display_map();
}
