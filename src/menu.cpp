#include <Employee.h>
#include <arrowInput.h>
#include <menu.h>
#include <myprint.h>

#include <iostream>
void renderMenu(const char* color, int x, int y, int selected) {
  gotoxy(x, y);

  switch (selected) {
    case 0:
      gotoxy(x, y);
      setColor(color);
      std::cout << "new Employee" << std::endl;
      setColor("RESET");
      gotoxy(x, ++y);
      std::cout << "Display" << std::endl;
      gotoxy(x, ++y);
      std::cout << "Exit" << std::endl;
      break;
    case 1:
      gotoxy(x, y);
      std::cout << "new Employee" << std::endl;

      gotoxy(x, ++y);
      setColor(color);
      std::cout << "Display" << std::endl;
      setColor("RESET");
      gotoxy(x, ++y);
      std::cout << "Exit" << std::endl;
      break;
    case 2:

      gotoxy(x, y);
      std::cout << "new Employee" << std::endl;
      gotoxy(x, ++y);
      std::cout << "Display" << std::endl;
      gotoxy(x, ++y);
      setColor(color);
      std::cout << "Exit" << std::endl;
      break;

    default:
      break;
  }
}

void menu(const char* color, int x = 0, int y = 0) {
  std::cout
      << "move with the arrow keys to test the program (press 'q' to quit):\n";

  char byte1 = 'q';
  char byte2 = 'q';
  char byte3 = 'q';

  int selected = 0;

  do {
    renderMenu(color, x, y, selected);  // render first time

    // Read a key from the user
    byte1 = getch_linux();
    // If the key is the beginning of an arrow-key escape sequence
    if (byte1 == '\033') {  // ^[
      // Skip the second character '['
      byte2 = getch_linux();
      byte3 = getch_linux();
      // The third character determines the arrow direction
      switch (byte3) {
        case 'A':  // ↑ Up Arrow

          selected = selected > 0 ? (selected - 1) : 2;
          // renderMenu("green", x, y, selected); not needed
          break;

        case 'B':  // ↓ Down Arrow
          selected = (selected + 1) % 3;
          // renderMenu("green", x, y, selected);  not needed
          break;
      }
    } else if (byte1 == '\n' && selected == 0) {  // first op selected
      setColor("CLEAR");
      gotoxy(1, 1);
      // std::cout << "Enter the number of employees to be added: \n";
      // int size = 0;
      // std::cin >> size;
      // newEmpStatic(size);
      newEmpDynamic();
    }

  } while (byte1 != 'q' && byte1 != 'Q' && byte1 != '\n');
}

void newEmpStatic(const int size) {
  Employee
      emparray[size];  // hade to make an empty constructor for this to work

  for (int i = 0; i < size; i++) {
    float salary = 0;
    char name[32];
    std::cout << "Enter the name of employee number  " << i + 1 << " :";
    std::cin >> name;

    std::cout << "Enter the salary of employee number  " << i + 1 << " :";
    std::cin >> salary;

    emparray[i] = Employee(name, salary);
  }

  std::cout << emparray[0].getName() << std::endl;
  std::cout << emparray[1].getName() << std::endl;
}

void extendSize(Employee** emparray, int& currentSize) {
  Employee* temp = new Employee[currentSize * 2];

  for (int i = 0; i < currentSize; i++) {
    temp[i] = (*emparray)[i];
  }

  *emparray = temp;
  currentSize *= 2;
}

void newEmpDynamic() {
  int currentSize = 2;
  Employee* emparray =
      new Employee[currentSize];  // hade to make an empty constructor for this
                                  // to work
  char flag;
  int index = 0;
  do {
    if (index == currentSize) extendSize(&emparray, currentSize);
    float salary = 0;
    char name[32];
    std::cout << "Enter the name of employee number  " << index + 1 << " :";
    std::cin >> name;

    std::cout << "Enter the salary of employee number  " << index + 1 << " :";
    std::cin >> salary;

    emparray[index] = Employee(name, salary);
    index++;
    std::cout << "another employee => any char , quit => q \n";
    std::cin >> flag;
  } while (flag != 'q');

  std::cout << emparray[0].getName() << std::endl;
  std::cout << emparray[1].getName() << std::endl;
  std::cout << emparray[2].getName() << std::endl;
}