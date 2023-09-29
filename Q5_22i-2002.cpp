#include <iostream>
using namespace std;

// Function to count inversions in the 2D array
int countInversions(int** array, int row, int col) {
   //base case
    if (row < 1 || col < 1)
        return 0;

    int inversions = 0;

    // Compare the current elements with elements below it
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int x = i + 1; x < row; x++) {
                for (int y = 0; y < col; y++) {
                    // Check if it's an inversion
                    if (i < x && array[i][j] > array[x][y]) {
                        inversions++;
                    }
                }
            }
        }
    }

    // Recursively count inversions in the submatrix
    int subInversions = countInversions(array, row - 1, col - 1);

    // Add the submatrix inversions to the total count
    inversions += subInversions;

    return inversions;
}

int main() {
    int row, col;

    // Input the dimensions of the 2D array
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    // Allocate memory for the 2D array dynamically
    int** array = new int* [row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[col];
    }

    // Input distinct elements into the array
    cout << "Enter distinct elements in the array:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> array[i][j];
        }
    }

    // Call the function to count inversions
    int inversions = countInversions(array, row, col);

    cout << "Number of inversions in the array: " << inversions << endl;

    // Deallocate memory for the 2D array
    for (int i = 0; i < row; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
