#include <iostream>
using namespace std;
void PrintPattern(int n) {
    if (n == 0) {
        return;  // Base case: stop recursion when n reaches 0
    }
    for (int i = 0; i < n; i++) {
        cout << n << " ";
    }
    for (int i = 0; i < n - 1; i++) {
        cout << "1 ";
    }
    cout << endl;

    // Recursive call with n-1
    PrintPattern(n - 1);
}

int main() {
    int num;
    cout << "Enter any number: ";
    cin >> num;

    if (num >= 0) {
        PrintPattern(num);
    }
    else {
        cout << "Please enter a non-negative number." << endl;
    }

    return 0;
}
