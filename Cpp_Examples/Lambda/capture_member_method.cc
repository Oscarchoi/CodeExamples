#include <iostream>
#include <string>

using namespace std;

class Person {
  public:
    Person(const string& name) : name_(name){};

    void Greet(const string& name){
      std::cout<<"Hi "<<name<<", I am "<<name_<<std::endl;
    }

    auto GetGreet(){
      return [this](){ Greet("nobody"); };
    }
    
    void SetName(const string& new_name){
      name_ = new_name;
    }

  private:
    string name_;
};

int main(){
  Person A("Choi");

  auto callback = A.GetGreet();
  callback();

  A.SetName("Kim");
  callback();
}

  



