#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Shape {
  virtual string str() const = 0;
};

struct Circle : Shape {
  float radius;
  Circle(const float &radius) : radius(radius) {}
  void resize(float factor) { radius *= factor; }
  string str() const override {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

template <typename T> struct ColoredShape : T {
  static_assert(is_base_of<Shape, T>::value,
                "Template argument must be a Shape");

  template <typename... Args>
  ColoredShape(const string &color, Args... args)
      : T(std::forward<Args>(args)...), color{color} {}
  // Aggregation을 쓰지 않고 상속하는 T를 초기화

  string color;
  string str() const override {
    ostringstream oss;
    oss << T::str() << " has the color " << color;
    return oss.str();
  }
};

template <typename T> struct TransparentShape : T {
  static_assert(is_base_of<Shape, T>::value,
                "Template argument must be a Shape");

  template <typename... Args>
  TransparentShape(const uint8_t &transparency, Args... args)
      : T(std::forward<Args>(args)...), transparency{transparency} {}
  // Aggregation을 쓰지 않고 상속하는 T를 초기화

  uint8_t transparency;
  string str() const override {
    ostringstream oss;
    oss << T::str() << " has "
        << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
    return oss.str();
  }
};

int main() {
  TransparentShape<ColoredShape<Circle>> circle{51, "red", 0.85};
  std::cout << circle.str() << std::endl;
}
