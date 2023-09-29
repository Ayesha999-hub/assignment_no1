#include <iostream>
using namespace std;
void calculateSum(int** arr, int rows, int cols, int* evenSum, int* oddSum) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] % 2 == 0) {
                *evenSum += arr[i][j];
            }
            else {
                *oddSum += arr[i][j];
            }
        }
    }
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a dynamic 2D array (pointer to pointer)
    int** arr = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols]; // Allocate memory for each row
    }

    // Input data into the 2D array
    cout << "Enter the elements of the " << rows << "x" << cols << " array:" << std::endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }

    int evenSum = 0;
    int oddSum = 0;

    calculateSum(arr, rows, cols, &evenSum, &oddSum);

    cout << "Sum of even numbers: " << evenSum <<endl;
    cout << "Sum of odd numbers: " << oddSum << endl;

    // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
