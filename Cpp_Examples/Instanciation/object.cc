#include "object.h"

#include <iostream>

template <int N>
void Object<N>::SayHello() {
  std::cout << "Hello! I'm object " << N << std::endl;
}

template class Object<1>;

#define INSTALL(label) template class Object<label>;
INSTALL(2)
#undef INSTALL