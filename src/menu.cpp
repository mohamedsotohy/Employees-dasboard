#include <Employee.h>
#include <arrowInput.h>
#include <menu.h>
#include <myprint.h>
#include <mystring.h>

#include <iostream>

template <typename T>
#define SKIPPED_CHARS 100000

void validateNumber(T& src, T min, T max) {
  while (!(std::cin >> src) || src < min || src > max) {
    std::cout << "Invalid input. Please enter a number between " << min
              << " and " << max << ": ";
    std::cin.clear();
    std::cin.ignore(SKIPPED_CHARS, '\n');
  }
  std::cin.ignore(SKIPPED_CHARS, '\n');
}

// void validateName(char* src, int min, int max) {
//   bool valid;
//   do {
//     std::cin >> src;
//     int size = getLength(src);
//     valid = (size >= min && size <= max);

//     if (!valid) {
//       std::cout << "Invalid input. number of characters between " << min
//                 << " and " << max << ": ";
//       std::cin.clear();
//       std::cin.ignore(SKIPPED_CHARS, '\n');
//     }
//   } while (!valid);
//   std::cin.ignore(SKIPPED_CHARS, '\n');
// }

void validateName(char* src, int min, int max) {
  std::cin.ignore(1, '\n');
  bool valid = false;
  while (!valid) {
    std::cin.getline(src, max + 1);
    if (std::cin.fail()) {  // line was longer than max
      std::cin.clear();
      std::cin.ignore(SKIPPED_CHARS, '\n');
    } else {
      valid = getLength(src) >= min;
    }
    if (!valid) {
      std::cout << "Invalid input. number of characters between " << min
                << " and " << max << ": ";
    }
  }
}

void renderMenu(const char* color, int x, int y, int marked) {
  gotoxy(x, y);

  switch (marked) {
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
      setColor("RESET");
      break;

    default:
      break;
  }
}

void menu(const char* color, int x, int y, char type) {
  char byte1 = 'q';
  char byte2 = 'q';
  char byte3 = 'q';

  int selected = 0;
  int currentIndex = 0;
  int currentSize = 2;

  Employee* dEmpArray = new Employee[currentSize];

  Employee sEmpArray[currentSize];

  do {
    setColor("CLEAR");
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
          break;

        case 'B':  // ↓ Down Arrow
          selected = (selected + 1) % 3;
          break;
      }
    } else if (byte1 == '\n') {
      setColor("CLEAR");
      switch (selected) {
        case 0:  // new employee
          if (type == 'd')
            currentIndex = newEmpDynamic(&dEmpArray, currentIndex, currentSize);
          else {
            gotoxy(1, 1);
            std::cout << "Enter the number of employees to be added: \n";
            validateNumber(currentSize, 1, 100);
            if (currentSize <= 0 || currentSize > 500) {
              std::cout << "invalid size";
              break;
            }
            currentIndex = newEmpStatic(sEmpArray, currentSize, currentIndex);
          }

          break;
        case 1:  // display
          type == 'd' ? display(currentIndex, dEmpArray)
                      : display(currentIndex, sEmpArray);
          break;
        case 2:
          byte1 = 'q';
          break;

        default:
          break;
      }
    }

  } while (byte1 != 'q' && byte1 != 'Q');
}

int newEmpStatic(Employee* empArray, const int size, int currentIndex) {
  for (; currentIndex < size; currentIndex++) {
    float salary = 0;
    char name[32];
    std::cout << "Enter the name of employee number  " << currentIndex + 1
              << " :";
    std::cin >> name;

    std::cout << "Enter the salary of employee number  " << currentIndex + 1
              << " :";
    validateNumber(salary, (float)100, (float)1000000);

    empArray[currentIndex] = Employee(name, salary);
  }
  return currentIndex;
}

void extendSize(Employee** empArray, int& currentSize) {
  Employee* temp = new Employee[currentSize * 2];

  for (int i = 0; i < currentSize; i++) {
    temp[i] = (*empArray)[i];
  }

  *empArray = temp;
  currentSize *= 2;
}

int newEmpDynamic(Employee** emparray, int currentIndex, int currentSize) {
  char flag;
  do {
    if (currentIndex == currentSize) extendSize(emparray, currentSize);
    float salary = 0;
    char name[32] = {0};
    std::cout << "Enter the name of employee number  " << currentIndex + 1
              << " :";
    validateName(name, 1, 40);

    std::cout << "Enter the salary of employee number  " << currentIndex + 1
              << " :";
    validateNumber(salary, (float)100, (float)1000000);

    (*emparray)[currentIndex] = Employee(name, salary);
    currentIndex++;
    std::cout << "another employee => any char , quit => q \n";
    std::cin >> flag;
  } while (flag != 'q');
  setColor("CLEAR");
  return currentIndex;
}

void display(int index, Employee* emparr) {
  for (int i = 0; i < index; i++) {
    std::cout << emparr[i].getName() << " : " << emparr[i].getSalary() << "$"
              << std::endl;
  }
  std::cout << "END OF DISPLAY PRESS Enter TO PROCEED TO MAIN MENU"
            << std::endl;
  std::cin.ignore();  // count =1 , delimter = '\n'
                      // ignores one char consuming the leftover \n
                      // fixing previous error
  std::cin.get();
}
