#include<iostream>
using namespace std;

void ChangeLocation(char* Array, int b1, int b2) {
    if (b1 >= b2) {
        return; // No elements to be swaped
    }
    // Swap the elements at b1 and b2
    char temp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = temp;

    // Recursively calling the function
    ChangeLocation(Array, b1 + 1 , b2 - 1);
}

int main() {
    char array[8] = { 'P', 'A', 'K', 'I', 'S', 'T', 'A', 'N' };
    int b1 , b2;
    cout << "enter first index to be swaped : ";
    cin >> b1;
    cout << "enter second index to be swaped : ";
    cin >> b2;
    cout << "Original Array: ";
    for (int i = 0; i < 8; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

   ChangeLocation(array, b1, b2);

    cout << "Modified Array: ";
    for (int i = 0; i < 8; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

