#include <cmath>

struct Point {
  float x, y;
  friend class PointFactory;

private:
  Point(float x, float y) : x(x), y(y){};
};

struct PointFactory {
  static Point NewCartesian(float x, float y) { return Point(x, y); }
  static Point NewPolar(float r, float theta) {
    return Point(r * cos(theta), r * sin(theta));
  }
};

int main() { auto my_point = PointFactory::NewCartesian(1, 2); }