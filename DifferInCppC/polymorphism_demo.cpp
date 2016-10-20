//参考：http://www.cplusplus.com/doc/tutorial/polymorphism/
#include <iostream>
using namespace std;

class Polygon {
protected:
  int width_, height_;

public:
  Polygon(int width, int height) : width_(width), height_(height) {
    cout << "Polygon Constructing..." << endl;
  }
  virtual ~Polygon() { cout << "Polygon Destructing..." << endl; }
  virtual void area() = 0;
};

class Rectangle : public Polygon {
public:
  Rectangle(int width, int height) : Polygon(width, height) {
    cout << "Rectangle Constructing..." << endl;
  }
  virtual ~Rectangle() { cout << "Rectangle Destructing..." << endl; };
  void area() {
    cout << "Rectangle Width:" << width_ << ",Height" << height_ << endl;
    cout << "Rectangle Area:" << width_ * height_ << endl;
  }
};

class Triangle : public Polygon {
public:
  Triangle(int width, int height) : Polygon(width, height) {}
  virtual ~Triangle() { cout << "Triangle Destructing..." << endl; }
  void area() {
    cout << "Triangle Width:" << width_ << ",Height" << height_ << endl;
    cout << "Triangle Area:" << width_ * height_ / 2 << endl;
  }
};

int main() {
  Polygon *ppoly_rec = new Rectangle(4, 5);
  ppoly_rec->area();
  delete ppoly_rec;

  cout << endl << endl;

  Polygon *ppoly_tri = new Triangle(4, 5);
  ppoly_tri->area();
  delete ppoly_tri;
}
