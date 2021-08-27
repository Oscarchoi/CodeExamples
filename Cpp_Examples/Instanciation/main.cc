#include <string>

#include "object.h"

int main() {
  Object<1> obj_1;
  obj_1.SayHello();

  Object<2> obj_2;
  obj_2.SayHello();

  return 0;
}