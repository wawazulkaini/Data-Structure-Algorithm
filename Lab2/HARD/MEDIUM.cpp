/*
NUR ADWA NAYLI BINTI ZULKAINI
22011769

MEDIUM
- ROTATE MATRIX BY 180 DEGREE
*/



#include <iostream>
#include <vector>
using namespace std;


void rotate180(vector<vector<int>>& matrix) {
    int n = matrix.size();

    
    vector<vector<int>> rotated(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[i][j] = matrix[n - 1 - i][n - 1 - j];
        }
    }

    
    matrix = rotated;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate180(matrix);
    
//Display
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}