// #ifdef _WIN32
// #include <windows.h>

// #endif

#ifndef MYPRINT_H
#define MYPRINT_H

const char* const RESET = "\033[0m";  // excap , control , color_code , end
const char* const CLEAR = "\033[2J";
const char* const RED = "\033[31m";
const char* const GREEN = "\033[32m";
const char* const YELLOW = "\033[33m";
const char* const BLUE = "\033[34m";
const char* const MAGENTA = "\033[35m";
const char* const CYAN = "\033[36m";
const char* const BLACK = "\033[30m";
const char* const WHITE = "\033[37m";

void gotoxy(int x, int y);
void setColor(const char* color);

#endif