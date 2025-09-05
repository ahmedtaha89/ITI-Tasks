#include <iostream>
using namespace std;

class Numbers {
private:
    int num1=0;
    int num2=0;
    int num3=0;

public:
    // Setter & Getter for num1
    void setNum1(int a) {
        num1 = a;
    }
    int getNum1() {
        return num1;
    }

    // Setter & Getter for num2
    void setNum2(int b) {
        num2 = b;
    }
    int getNum2() {
        return num2;
    }

    // Setter & Getter for num3
    void setNum3(int c) {
        num3 = c;
    }
    int getNum3() {
        return num3;
    }




    void sum(){
        cout << "Sum " << num1+num2+num3;
    }
};


int main(){

    Numbers n1;
    n1.setNum1(10);
    n1.setNum2(10);
    // n1.setNum3(10);
    n1.sum();
    Numbers n2;

    return 0;
}
