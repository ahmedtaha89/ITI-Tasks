#include <iostream>
using namespace std;

class Mother {
public:
    void display() {
        cout << "Hello this is Parent class" << endl;
    }
};

class Daughter : public Mother {
public:
    void display() {
        cout << "Hello this is Sub class" << endl;
    }
};

int main() {
    Mother M1;
    Daughter d1;

    d1.display();
    M1.display();

    return 0;
}
