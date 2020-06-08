#include <memory>
#include <string>

class PersonImpl {
public:
  PersonImpl(const std::string &name, const int &age);
  std::string name() const;
  int age() const;

private:
  std::string _name;
  int _age;
};
