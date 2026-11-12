#include <myprint.h>
#include <mystring.h>

#include <iostream>

void gotoxy(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }

void setColor(const char* color) {
  if (strCmp(color, "CLEAR"))
    std::cout << CLEAR;
  else if (strCmp(color, "RESET"))
    std::cout << RESET;
  else if (strCmp(color, "RED"))
    std::cout << RED;
  else if (strCmp(color, "GREEN"))
    std::cout << GREEN;
  else if (strCmp(color, "BLACK"))
    std::cout << Black;
  else if (strCmp(color, "YELLOW"))
    std::cout << YELLOW;
  else if (strCmp(color, "BLUE"))
    std::cout << BLUE;
  else if (strCmp(color, "MAGNETA"))
    std::cout << Magenta;
  else if (strCmp(color, "CYAN"))
    std::cout << Cyan;
  else if (strCmp(color, "WHITE"))
    std::cout << White;
  else
    std::cout << RESET;
}
