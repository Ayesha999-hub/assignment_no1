#include <iostream>
using namespace std;
bool CheckEqualSumArrays(int** A1, int** A2, int** A3, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A1[i][j] + A2[i][j] != A3[i][j]) {
                return false;
            }
        }
    }
    return true;
}
// Function to check if the difference of any two arrays is equal to the third array
bool CheckDifferentArrays(int** A1, int** A2, int** A3, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A1[i][j] - A2[i][j] != A3[i][j]) {
                return false;
            }
        }
    }
    return true;
}
bool AreArraysEqual(int** A1, int** A2) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (A1[i][j] != A2[i][j]) {
                return false;
            }
        }
    }
    return true;
}
// Function to check if two rows are identical
bool areRowsEqual(int* row1, int* row2, int cols) {
    for (int i = 0; i < cols; i++) {
        if (row1[i] != row2[i]) {
            return false;
        }
    }
    return true;
}
// Function to find the same rows in three 2D arrays
void FindSameRows(int** A1, int** A2, int** A3, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bool foundInAll = true;

        // Check if the current row in A1 is present in A2 and A3
        for (int j = 0; j < rows; j++) {
            if (!areRowsEqual(A1[i], A2[j], cols) && !areRowsEqual(A1[i], A3[j], cols)) {
                foundInAll = false;
                break;
            }
        }

        // If the current row is found in all three arrays, print it
        if (foundInAll) {
            cout << "Row " << i << " is the same in all three arrays." << endl;
        }
    }
}



void RotateArrays(int** A1, int** A2, int** A3, int n) {
    // Create temporary arrays to store the rotated values
    int** tempA1 = new int* [n];
    int** tempA2 = new int* [n];
    int** tempA3 = new int* [n];

    for (int i = 0; i < n; i++) {
        tempA1[i] = new int[n];
        tempA2[i] = new int[n];
        tempA3[i] = new int[n];
    }

    // Perform the rotation for A1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempA1[j][n - 1 - i] = A1[i][j];
        }
    }

    // Perform the rotation for A2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempA2[j][n - 1 - i] = A2[i][j];
        }
    }

    // Perform the rotation for A3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempA3[j][n - 1 - i] = A3[i][j];
        }
    }

    // Copy the rotated arrays back to A1, A2, and A3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A1[i][j] = tempA1[i][j];
            A2[i][j] = tempA2[i][j];
            A3[i][j] = tempA3[i][j];
        }
    }

    // Free the memory used by temporary arrays
    for (int i = 0; i < n; i++) {
        delete[] tempA1[i];
        delete[] tempA2[i];
        delete[] tempA3[i];
    }
    delete[] tempA1;
    delete[] tempA2;
    delete[] tempA3;
}

int main() {
    int rows, cols;
    int n = 3;
    // Input the number of rows and columns for the 2D arrays
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate memory for the three 2D arrays
    int** A1 = new int* [rows];
    int** A2 = new int* [rows];
    int** A3 = new int* [rows];

    for (int i = 0; i < rows; i++) {
        A1[i] = new int[cols];
        A2[i] = new int[cols];
        A3[i] = new int[cols];
    }

    // Input values for the three arrays
    cout << "Enter values for Array 1:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A1[i][j];
        }
    }

    cout << "Enter values for Array 2:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A2[i][j];
        }
    }

    cout << "Enter values for Array 3:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A3[i][j];
        }
    }

    // Check if the sum of any two arrays is equal to the third array
    if (CheckEqualSumArrays(A1, A2, A3, rows, cols)) {
        std::cout << "The sum of Array 1 and Array 2 is equal to Array 3." << std::endl;
    }
    else {
        std::cout << "The sum of Array 1 and Array 2 is not equal to Array 3." << std::endl;
    }
    if (CheckDifferentArrays(A1, A2, A3, rows, cols)) {
        cout << "The difference of Array 1 and Array 2 is equal to Array 3." << std::endl;
    }
    else {
        cout << "The differnce of Array 1 and Array 2 is not equal to Array 3." << std::endl;
    }
    if (CheckDifferentArrays(A1, A2, A3, rows, cols)) {
        cout << "The difference of Array 1 and Array 2 is equal to Array 3." << std::endl;
    }
    else {
        cout << "The differnce of Array 1 and Array 2 is not equal to Array 3." << std::endl;
    }
    if (AreArraysEqual(A1, A2 )) {
        cout << "Two of the arrays is equal ." << std::endl;
    }
    else {
        cout << "none of the array  is equal" << std::endl;
    }
    FindSameRows(A1, A2, A3, rows, cols);
    RotateArrays(A1, A2, A3, n);

    // Print the rotated arrays
    cout << "Rotated A1:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A1[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Rotated A2:\n";
    // Print rotated A2 similarly

    cout << "Rotated A3:\n";
    // Print rotated A3 similarly

    

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] A1[i];
        delete[] A2[i];
        delete[] A3[i];
    }
    delete[] A1;
    delete[] A2;
    delete[] A3;

    return 0;
}
