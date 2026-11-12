

struct Employee {
 private:
  const char* name;
  int salary;

 public:
  Employee(const char* name, int salary);
  Employee();
  const char* getName();
  void incSalary(float rate);
};
