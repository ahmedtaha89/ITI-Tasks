#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i" << endl;
        else
            cout << " - " << -imag << "i" << endl;
    }

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex sub(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex mul(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex div(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        return Complex(r, i);
    }
};

int main() {
    Complex c1(4, 5);
    Complex c2(2, -3);

    Complex sum = c1.add(c2);
    Complex diff = c1.sub(c2);
    Complex mul = c1.mul(c2);
    Complex div = c1.div(c2);

    cout << "First Complex number: ";
    c1.display();

    cout << "Second Complex number: ";
    c2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    cout << "Multiplication: ";
    mul.display();

    cout << "Division: ";
    div.display();

    return 0;
}
