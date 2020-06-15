#include <iostream>
#include <map>
#include <memory>
#include <string>
using namespace std;

struct HotDrink {
  virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {
  void prepare(int volume) override {
    cout << "Take tea - " << volume << "ml" << endl;
  };
};

struct Coffee : HotDrink {
  void prepare(int volume) override {
    cout << "Take Coffee - " << volume << "ml" << endl;
  };
};

unique_ptr<HotDrink> make_drink(string type) {
  unique_ptr<HotDrink> drink;
  if (type == "coffee") {
    drink = make_unique<Coffee>();
    drink->prepare(200);
  } else {
    drink = make_unique<Tea>();
    drink->prepare(300);
  }
  return drink;
}

// let's introduce the factory for each drink.

// this factory is an abstract factory
struct HotDrinkFactory {
  virtual unique_ptr<HotDrink> make() const = 0;
};

struct CoffeeFactory : HotDrinkFactory {
  unique_ptr<HotDrink> make() const override { return make_unique<Coffee>(); }
};
struct TeaFactory : HotDrinkFactory {
  unique_ptr<HotDrink> make() const override { return make_unique<Tea>(); }
};

class DrinkFactory {
  map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
  DrinkFactory() {
    hot_factories["coffee"] = make_unique<CoffeeFactory>();
    hot_factories["tea"] = make_unique<TeaFactory>();
  }
  unique_ptr<HotDrink> make_drink(const string &name) {
    auto drink = hot_factories[name]->make();
    drink->prepare(200);
    return drink;
  }
};