#include <iostream>
using namespace std;
int sum(int a = 0,int b = 0,int c =0,int d = 0);

int main(){
int num1 = 10,num2 = 20,num3 = 30,num4 = 40;
cout << "Sum(4 Numbers): " << sum(num1,num2,num3,num4) << endl;
cout << "Sum(3 Numbers): " << sum(num1,num2,num3) << endl;
cout << "Sum(2 Numbers): " << sum(num1,num2) << endl;
cout << "Sum(0 Numbers): " << sum() << endl;

}


int sum(int a, int b, int c, int d){
return a + b + c + d;
}