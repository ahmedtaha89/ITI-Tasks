#include <iostream>
#include <iomanip>
using namespace std;

void magic_square(int size) {
    if (size % 2 == 0) {
        cout << "Only odd numbers are allowe\n";
        return;
    }

    int square[99][99] = {0};

    int row = 0;
    int col = size / 2;
    int value = 1;

    while (value <= size * size) {
        square[row][col] = value;

        int nextRow = row - 1;
        int nextCol = col - 1;

        if (nextRow < 0) nextRow = size - 1;
        if (nextCol < 0) nextCol = size - 1;

        if (square[nextRow][nextCol] != 0) {
            row = (row + 1) % size;
        } else {
            row = nextRow;
            col = nextCol;
        }

        value++;
    }

    cout << "\nMagic Square of size " << size << ":\n\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) << square[i][j];
        }
        cout << endl;
    }
}

int main() {
    int size;
    do {
        cout << "Enter an odd number for the size: ";
        cin >> size;
    } while (size % 2 == 0 || size <= 0 || size > 99);

    magic_square(size);

    return 0;
}
