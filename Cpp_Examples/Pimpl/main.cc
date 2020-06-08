#include "person.h"

#include <iostream>

int main() {
  Person p("choi", 28);
  std::cout << p.name() << ":" << p.age() << std::endl;
  return 0;
}