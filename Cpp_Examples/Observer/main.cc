#include "observable.h"
#include "observer.h"

#include <iostream>
#include <string>
using namespace std;

struct Person : Observable<Person> {
  int get_age() const { return age; };
  void set_age(int age) {
    if (this->age == age)
      return;
    this->age = age;
    notify(*this, "age");
  };
  Person(int age) : age{age} {};

private:
  int age;
};

struct ConsolePersonObserver : Observer<Person> {
  void field_changed(Person &source, const std::string &field_name) override {
    std::cout << "Person's " << field_name << " has changed to "
              << source.get_age() << endl;
  };
};

int main() {
  Person p{28};
  ConsolePersonObserver cpo;
  p.subscribe(&cpo);
  p.set_age(29);
  p.set_age(30);
  return 0;
}
