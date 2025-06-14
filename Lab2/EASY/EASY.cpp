/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769

EASY
- SORT A MATRIX IN ALL WAY INCREASING NUMBER

*/

#include <iostream>
#include <algorithm>  // for sort
using namespace std;

const int SIZE = 3;

void sortMatrix(int matrix[SIZE][SIZE]) {
    int temp[SIZE * SIZE];
    int index = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[index++] = matrix[i][j];

    sort(temp, temp + SIZE * SIZE);

    index = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = temp[index++];
}

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 0, 3},
        {2, 5, 6},
        {9, 4, 8}
    };

    sortMatrix(matrix);

//Display matrix

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}