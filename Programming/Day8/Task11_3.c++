#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    int age;

public:
    void set_name(string n) {
        name = n;
    }

    void set_age(int a) {
        age = a;
    }
};

class Zebra : public Animal {
public:
    Zebra(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Animal name is " << name
             << " Age is " << age
             << "\nPlace of origin is Croatia" << endl;
    }
};

class Dolphin : public Animal {
public:
    Dolphin(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Animal name is " << name
             << " Age is " << age
             << "\nPlace of origin is Maldives" << endl;
    }
};

int main() {
    Zebra Z1("Zebra", 7);
    Dolphin D1("Dolphin", 15);

    Z1.display();
    D1.display();

    Z1.set_name("Zozo");
    Z1.set_age(10);
    Z1.display();

    return 0;
}
