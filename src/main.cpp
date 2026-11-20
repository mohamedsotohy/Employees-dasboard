#include <Employee.h>
#include <menu.h>

#include <iostream>
int main() {
  char type;
  std::cout << "Enter 's' for static array or 'd' for a dynamic array \n";
  std::cin >> type;
  menu("CYAN", 4, 4, type);
  // sEmployee one = sEmployee("Ahmed", 3000);
  // std::cout << one.getName();
  // std::cout << one.getName();
  // std::cout << one.getName();
  // // std::cout << "\033[2J";

  return 0;
}