/*
 * Autor       : Mikael Nilsson
 * Filename    : main.cpp
 * Description : C++ Screen example
 * Version     : 0.2
 *
*/

#if DEBUG
#include <memstat.hpp>
#endif
#include "screen.h"
#include <iostream>

using namespace std;

int main() {
    Terminal terminal;
    // Rektangel
    Screen screen(80, 24);
    screen.fill(' ', TerminalColor(COLOR::GREEN, COLOR::BLUE));
    screen.fillRect(1,1,10,12,'A', COLOR::YELLOW);
    screen.setTextRect(15,12,6,3, "Hello World!", COLOR::RED);
    screen.draw(terminal);
    screen.clear();
    // Text
    screen.set(20, 12, 'L', COLOR::WHITE);
    screen.setText(20, 12, "Hej!", COLOR::CYAN);
    screen.draw(terminal);
    return 0;
}

