#include "Utils.h"

void clear_screen() {
    std::cout << "\033[2J\033[H"; // Clear screen and move cursor to the top
}
