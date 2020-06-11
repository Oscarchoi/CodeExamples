#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Shape {
  virtual string str() const = 0;
};

struct Circle : Shape {
  float radius;
  explicit Circle(const float radius) : radius(radius) {}
  void resize(float factor) { radius *= factor; }
  string str() const override {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

// 동적 데커레이터
struct ColoredShape : Shape {
  // ColoredShape은 그 자체로도 Shape이다.
  Shape &shape;
  string color;

  ColoredShape(Shape &shape, const string &color)
      : shape{shape}, color{color} {}

  string str() const override {
    ostringstream oss;
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape {
  Shape &shape;
  uint8_t transparency;

  TransparentShape(Shape &shape, const uint8_t transparency)
      : shape{shape}, transparency{transparency} {}

  string str() const override {
    ostringstream oss;
    oss << shape.str() << " has "
        << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
    return oss.str();
  }
};

int main() {
  Circle circle{0.5f};

  ColoredShape redCircle{circle, "red"};
  std::cout << redCircle.str() << std::endl;
  // OUTPUT: A circle of radius 0.5 has the color red

  TransparentShape demiCircle{redCircle, 85};
  std::cout << demiCircle.str() << std::endl;
  // OUTPUT: A circle of radius 0.5 has the color red has 33.3333% transparency
}