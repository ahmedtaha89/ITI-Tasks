#include <iostream>
using namespace std;

class Student{
// Attributes
private:
string name;
int age;
string phone;

//Methods
public:
void setname(string n){
name = n;
};

string getname(){
    return name;
};


void setage(int ag){
if(ag > 0)
{
    age = ag;
}
else 
cout << "Invaild"; 
};


int getage()
{
    return age;
};



void printstudent()
{
    cout <<"Name: "<< name << ", Age " << age <<endl; 
}



};


int main(){
Student s1;
s1.setname("ahmed");
s1.setage(23);
s1.printstudent();


Student s2;
s2.setname("ali");
s2.setage(25);
s2.printstudent();


    return 0;
}