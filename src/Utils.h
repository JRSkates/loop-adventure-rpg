#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cctype>
#include <string>

// Clears the terminal screen
void clear_screen();

void continue_screen();
void continue_screen_clear_buffer();

std::string trim(const std::string& str);
#endif // UTILS_H
