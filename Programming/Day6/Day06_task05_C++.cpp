#include <iostream>
#include <iomanip>
using namespace std;

void magic_square() {
    int square[4][4];
    int value = 1;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            square[i][j] = value++;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if ((i == j) || (i + j == 3) || 
                (i < 2 && j < 2) || (i >= 2 && j >= 2))
                square[i][j] = 17 - square[i][j];

    cout << "Magic Square 4*4:\n\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << setw(4) << square[i][j];
        cout << endl;
    }
}

int main() {
    magic_square();
    return 0;
}
