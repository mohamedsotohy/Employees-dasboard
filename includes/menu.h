// class Employee;

void renderMenu(const char* color, int x, int y, int selected);

void menu(const char* color, int x = 0, int y = 0, char type = 'd');

int newEmpStatic(Employee* empArray, const int size, int currentIndex);

int newEmpDynamic(Employee** emparray, int currentIndex, int currentSize);

void extendSize(Employee** emparray, int& currentSize);

void display(int index, Employee* emparr);