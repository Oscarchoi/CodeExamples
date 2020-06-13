#include <iostream>

class Singleton {
private:
  Singleton() { std::cout << "Singleton is instanciated" << std::endl; };
  // 생성자를 private에 두어 외부에서의 생성을 막는다.

  Singleton(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton &operator=(const Singleton &) = delete;
  Singleton &operator=(Singleton &&) = delete;

public:
  static Singleton &getInstance() {
    static Singleton _instance;
    // 위 함수의 쓰레드 안정성은 C++11 버젼에서만 보장된다.
    // 컴파일러가 static 객체를 초기화하는 코드 앞 뒤로 락을 삽입하여
    // 초기화 와중에 동시에 다른 스레드에서 접근하는 것을 방지해주는지 확인해야
    // 한다.
    return _instance;
  }

  void print() { std::cout << "Hello" << std::endl; }
};

int main() {
  Singleton &instance = Singleton::getInstance(); // 객체 생성됨
  instance.print();
  Singleton &instance2 = Singleton::getInstance(); // 객체 생성되지 않음
  instance2.print();
  return 0;
}