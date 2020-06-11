#include <functional>
#include <iostream>
#include <string>
using namespace std;

struct Logger {
  function<void()> func;
  string name;

  Logger(const function<void()> &func, const string &name)
      : func{func}, name{name} {}

  void operator()() const {
    cout << "Entering " << name << endl;
    func();
    cout << "Exiting " << name << endl;
  }
};

template <typename Func> struct Logger2 {
  Func func;
  string name;

  Logger2(const Func &func, const string &name) : func{func}, name{name} {}
  void operator()() const {
    cout << "Entering " << name << endl;
    func();
    cout << "Exiting " << name << endl;
  }
};
// 로깅 인스턴스를 만들기 위한 편의 함수
template <typename Func> auto make_logger2(Func func, const string &name) {
  return Logger2<Func>{func, name};
}

template <typename R, typename... Args> struct Logger3 {
  Logger3(function<R(Args...)> func, const string &name)
      : func{func}, name{name} {}

  R operator()(Args... args) {
    cout << "Entering " << name << endl;
    R result = func(args...);
    cout << "Exiting " << name << endl;
    return result;
  }
  function<R(Args...)> func;
  string name;
};
template <typename R, typename... Args>
auto make_logger3(R (*func)(Args...), const string &name) {
  return Logger3<R, Args...>(std::function<R(Args...)>(func), name);
}

int add(int a, int b) { return a + b; }

int main() {
  Logger([]() { cout << "Hello" << endl; }, "HelloFunction")();

  auto logger2 =
      make_logger2([]() { cout << "Hello!" << endl; }, "HelloFunction2");
  logger2();

  auto logger3 = make_logger3(add, "Add");
  auto res = logger3(2, 3);
  cout << res << endl;
}