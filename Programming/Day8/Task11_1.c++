#include <iostream>
using namespace std;

class Shape {
protected:
    int width;
    int height;

public:
    Shape() {
    width = 0;
    height = 0;
    }

    Shape(int w, int h) {
    width = w;
    height = h;
    }

    virtual double area() {
        return 0;
    }
};

class Triangle : public Shape {
public:
    Triangle(int w, int h) : Shape(w, h) {}

    double area() override {
        return 0.5 * width * height;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : Shape(w, h) {}

    double area() override {
        return width * height;
    }
};

int main() {
    Triangle t1(5, 8);
    Rectangle r1(5, 10);

    cout << "Area of Triangle = " << t1.area() << endl;
    cout << "Area of Rectangle = " << r1.area() << endl;

    return 0;
}

