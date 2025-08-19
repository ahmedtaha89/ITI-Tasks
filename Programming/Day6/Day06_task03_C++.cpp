#include <iostream>
using namespace std;

namespace ahmed{
string name = "Ahmed";
}

namespace taha{
string name = "Taha";
}


int main() {
cout << "Hello " << ahmed::name << endl;
cout << "Hello " << taha::name;
    return 0;
}