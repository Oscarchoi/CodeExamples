#include <memory>
#include <string>

class PersonImpl;

class Person { // handle class
public:
  Person(const std::string &name, const int &age);
  std::string name() const;
  int age() const;

private:
  std::shared_ptr<PersonImpl> pImpl;
};