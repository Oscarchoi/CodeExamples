#include <iostream>

template <typename T> struct CuriousBase {
  void interface() { static_cast<T *>(this)->implementation(); }
  static void static_func() { T::static_sub_func(); }
};

struct Derived : CuriousBase<Derived> {
  void implementation() { std::cout << "Implemenatation" << std::endl; };
  static void static_sub_func();
};

int main() {
  Derived derived;
  derived.interface();
  return 0;
}