#include <iostream>
using namespace std;

// Define class BEFORE main
class Complex {
private:
    float real;
    float image;

public:
    // Setters
    void setReal(float r) { real = r; }
    void setImg(float img) { image = img; }

    // Getters
    float getReal() { return real; }
    float getImg() { return image; }

    // Print
    void print() {
        cout << real;
        if (image >= 0)
            cout << " + " << image << "i";
        else
            cout << " - " << -image << "i";
        cout << endl;
    }
};

int main() {
    Complex c1;
    c1.setReal(6);
    c1.setImg(5);

    cout << "Complex number is: ";
    c1.print();   // Output: 6 + 5i

    return 0;
}
