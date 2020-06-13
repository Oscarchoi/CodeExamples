#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
  Singleton(){};
  static mutex mtx;
  static Singleton *m_instance;

public:
  static Singleton &getInstance();
  void print() { std::cout << "Hello" << std::endl; }
};

Singleton &Singleton::getInstance() {
  if (m_instance == nullptr) {
    lock_guard<mutex> lock(mtx);
    if (m_instance == nullptr) {
      m_instance = new Singleton;
      std::cout << "Sigleton Object Instantiated." << std::endl;
    }
  }
  return *m_instance;
}

Singleton *Singleton::m_instance = nullptr;
mutex Singleton::mtx;

int main() {
  Singleton &instance = Singleton::getInstance();
  instance.print();
  Singleton &instance2 = Singleton::getInstance();
  instance2.print();
}