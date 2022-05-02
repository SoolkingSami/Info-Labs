#include <iostream>
#include <graphics.h>

using namespace std;

struct Point {
  double x, y;

  Point(double x, double y) : x(x), y(y) {}

  Point operator+(const Point& p) const {
    return Point(x + p.x, y + p.y);
  }

  Point operator-(const Point& p) const {
    return Point(x - p.x, y - p.y);
  }

  Point operator*(const int& k) const {
    return Point(x * k, y * k);
  }

  Point operator*=(const int& k) {
    x *= k;
    y *= k;
    return *this;
  }

  void swap(Point& p) {
    double tmp = x;
    x = p.x;
    p.x = tmp;
    tmp = y;
    y = p.y;
    p.y = tmp;
  }
};

struct Vector {
  Point px, py;

  Vector(Point px, Point py) : px(px), py(py) {}

  Vector(int x1, int y1, int x2, int y2) : px(x1, y1), py(x2, y2) {}

  Vector operator+(const Vector& v) const {
    return Vector(px + v.px, py + v.py);
  }

  Vector operator-(const Vector& v) const {
    return Vector(px - v.px, py - v.py);
  }

  Vector operator*(const int& k) const {
    return Vector(px * k, py * k);
  }

  Vector operator*=(const int& k) {
    px *= k;
    py *= k;
    return *this;
  }

  void reverse() {
    px.swap(py);
  }

  double getScalarProduct(const Vector& v) const {
    return px.x * v.px.x + px.y * v.px.y + py.x * v.py.x + py.y * v.py.y;
  }

  bool isPerpendicularOn(const Vector& v) const {
    return getScalarProduct(v) == 0;
  }
};

void line(Point p1, Point p2) {
  line(p1.x, p1.y, p2.x, p2.y);
}

int main() {
  initwindow(1000, 600, "Hello, world!", 100, 100);
  cleardevice();
  
  Point p1(100, 100);
  Point p2(200, 200);
  Point p3(300, 100);
  Vector v1(p1, p2);
  Vector v2(p2, p3);

  cout << v1.getScalarProduct(v2) << endl;
  cout << (v1.isPerpendicularOn(v2) ? "Perpendicular vectors" : "Non-perpendicular vectors") << endl;

  line(v1.px, v1.py);
  line(v2.px, v2.py);

  v2 *= 2;
  setcolor(GREEN);
  line(v2.px, v2.py);

  setcolor(BLUE);
  Vector v3(v1 + v2);
  line(v3.px, v3.py);

  getchar();
  closegraph();
  return 0;
}