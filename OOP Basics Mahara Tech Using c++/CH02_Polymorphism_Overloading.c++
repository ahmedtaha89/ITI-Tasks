#include <iostream>
using namespace std;

class PrintPoly{
    public:
        void show(int a){
            cout << "intger " << a <<endl;
        };

        void show(double a){
            cout << "Float " << a <<endl;
        };

        void show(string a){
            cout << "String " << a <<endl;
        }
};


int main(){
PrintPoly p1;

p1.show(1);
p1.show(2);
p1.show("ahmed");

    return 0;
}