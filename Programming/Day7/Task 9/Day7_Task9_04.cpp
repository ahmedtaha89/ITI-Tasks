#include <iostream>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(double x_, double y_) {
        x = x_;
        y = y_;
    }

    Point add(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point sub(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(3.5, 2.0);
    Point p2(1.0, -4.5);

    Point sum = p1.add(p2);
    Point diff = p1.sub(p2);

    cout << "First point: ";
    p1.print();

    cout << "Second point: ";
    p2.print();

    cout << "Sum: ";
    sum.print();

    cout << "Difference: ";
    diff.print();

    return 0;
}
