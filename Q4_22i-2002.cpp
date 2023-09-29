#include <iostream>
#include <algorithm> 
using namespace std;
void FindOccurrences(int* A, int size, int index) {
    if (index == size) {
        return;
    }

    int current = A[index];
    int count = 1;

    // Check for occurrences of the current number
    for (int i = index + 1; i < size; i++) {
        if (A[i] == current) {
            count++;
        }
    }

    // Mark the current number as processed
    for (int i = index; i < size; i++) {
        if (A[i] == current) {
            A[i] = -1;
        }
    }

    // Print the current number and its count
    if (current != -1) {
        cout << "Number " << current << endl;
       cout << "Occurrences " << count << endl;
    }

    FindOccurrences(A, size, index + 1);
}
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "Output:\n";
    FindOccurrences(arr, n, 0);



    return 0;
}

