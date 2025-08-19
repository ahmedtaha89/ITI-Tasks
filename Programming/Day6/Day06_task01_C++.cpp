#include <iostream>
using namespace std;

void swap(int &num1,int &num2);

int main() {
int a, b;
cout << "Please Enter Number 1:";
cin >> a;
cout << "Please Enter Number 2:";
cin >> b;

swap(a,b);
cout << "Number 1 After Swap: " << a <<endl;
cout << "Number 2 After Swap: " << b;

    return 0;
}


void swap(int &num1,int &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}