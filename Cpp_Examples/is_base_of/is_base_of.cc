#include <iostream>
#include <type_traits>

class A;

template <typename T>
inline constexpr bool IsClassA(T* t) {
  return std::is_same<A, T>::value;
}

class A {
 public:
  void Identify() {
    std::cout << std::boolalpha;
    std::cout << "I am A. Am I Class A? : " << IsClassA(this) << std::endl;
  }
};
class B : public A {
 public:
  void Identify() {
    std::cout << std::boolalpha;
    std::cout << "I am B. Am I Class A? : " << IsClassA(this) << std::endl;
  }
};

class C {};

int main() {
  std::cout << std::boolalpha;
  std::cout << "a2b: " << std::is_base_of<A, B>::value << std::endl;
  std::cout << "a2c: " << std::is_base_of<A, C>::value << std::endl;

  A a;
  a.Identify();

  B b;
  b.Identify();

  std::cout << "I am B. Am I Class A? : " << IsClassA(&b) << std::endl;
}
