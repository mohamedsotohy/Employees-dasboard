

#include "Employee.h"

#include <mystring.h>

#include <iostream>

Employee::Employee(const char* name, int salary) {
  stringCopy(name, &this->name);  // similer to andrews problem

  this->salary = salary;
}
Employee::Employee() {}
const char* Employee::getName() { return this->name; }
void Employee::incSalary(float rate) { this->salary += this->salary * rate; }
