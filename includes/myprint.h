// #ifdef _WIN32
// #include <windows.h>

// #endif

inline const char* RESET = "\033[0m";  // excap , control , color_code , end
inline const char* CLEAR = "\033[2J";
inline const char* RED = "\033[31m";
inline const char* GREEN = "\033[32m";
inline const char* YELLOW = "\033[33m";
inline const char* BLUE = "\033[34m";
inline const char* Magenta = "\033[35m";
inline const char* Cyan = "\033[36m";
inline const char* Black = "\033[30m";
inline const char* White = "\033[37m";

void gotoxy(int x, int y);
void setColor(const char* color);
