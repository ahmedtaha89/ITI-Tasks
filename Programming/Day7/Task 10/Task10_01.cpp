#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;
        if (denominator == 0) {
            cerr << "Error: Division by zero!" << endl;
            return Complex(0, 0);
        }
        double r = (real * c.real + imag * c.imag) / denominator;
        double i = (imag * c.real - real * c.imag) / denominator;
        return Complex(r, i);
    }

    Complex operator-() const {
        return Complex(-real, -imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main() {
    Complex c1, c2, result;

    cout << "Enter complex number c1:\n";
    cin >> c1;

    cout << "Enter complex number c2:\n";
    cin >> c2;

    cout << "\nResults:\n";
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    result = c1 + c2;
    cout << "c1 + c2 = " << result << endl;

    result = c1 - c2;
    cout << "c1 - c2 = " << result << endl;

    result = c1 * c2;
    cout << "c1 * c2 = " << result << endl;

    result = c1 / c2;
    cout << "c1 / c2 = " << result << endl;

    result = -c1;
    cout << "-c1 = " << result << endl;

    return 0;
}
