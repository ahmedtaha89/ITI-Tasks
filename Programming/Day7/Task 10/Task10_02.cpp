#include <iostream>
#include <cmath>
using namespace std;

class Poly {
private:
    double a, b, c;

public:
    Poly() : a(0), b(0), c(0) {}
    Poly(double coeffA, double coeffB, double coeffC) : a(coeffA), b(coeffB), c(coeffC) {}

    Poly operator+(const Poly& other) const {
        return Poly(a + other.a, b + other.b, c + other.c);
    }

    friend ostream& operator<<(ostream& out, const Poly& p) {
        bool firstTerm = true;

        if (p.a != 0) {
            out << p.a << "x^2";
            firstTerm = false;
        }

        if (p.b != 0) {
            if (!firstTerm) out << (p.b > 0 ? " + " : " - ");
            else if (p.b < 0) out << "-";
            out << abs(p.b) << "x";
            firstTerm = false;
        }

        if (p.c != 0 || firstTerm) {
            if (!firstTerm) out << (p.c > 0 ? " + " : " - ");
            else if (p.c < 0) out << "-";
            out << abs(p.c);
        }

        return out;
    }
};

int main() {
    Poly q1(3, 4, -2);
    Poly q2(0, -4, 10);
    Poly sum = q1 + q2;

    cout << q1 << " : q1\n";
    cout << q2 << " : q2\n";
    cout << sum << " : q1+q2\n";

    return 0;
}
