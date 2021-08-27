#include "object.h"

#include <iostream>

template <int N>
void Object<N>::SayHello() {
  std::cout << "Hello! I'm object " << N << std::endl;
}

template class Object<1>;
template class Object<2>;