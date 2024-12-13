#include "Utils.h"

void clear_screen() {
    std::cout << "\033[2J\033[H"; // Clear screen and move cursor to the top
}
void continue_screen() {
    std::cin.clear();
    std::cout << "Press Enter to continue... ";
    std::cin.get();
    clear_screen();
}

void continue_screen_clear_buffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    continue_screen();
}


std::string trim(const std::string& str) {
    auto start = str.find_first_not_of(" \t\n\r");
    auto end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos || end == std::string::npos) {
        return ""; // Return empty string if only whitespace
    }

    return str.substr(start, end - start + 1);
}
