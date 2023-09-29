#include <iostream>
#include <cstring>
using namespace std;

bool CheckSubsequent(char* str1, char* str2, int i, int j) {
    // If the second string is empty, it is always a subsequent.
    if (j == 0) {
        return true;
    }

    // If the first string is empty, but the second string is not, it can't be a subsequent
    if (i == 0) {
        return false;
    }

    // If the current characters match, move to the next character in both strings.
    if (str1[i - 1] == str2[j - 1]) {
        return CheckSubsequent(str1, str2, i - 1, j - 1);
    }

    // If the current characters do not match, skip a character in the first string.
    else
    return CheckSubsequent(str1, str2, i - 1, j);
}

int main() {
    char str1[100], str2[100];

    cout << "Enter String 1: "<<endl;
    cin >> str1 ;

    cout << "Enter String 2: " << endl;
    cin >> str2;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Call the recursive function with the lengths of both strings.
    if (CheckSubsequent(str1, str2, len1, len2)) {
        cout << "Output: True" << endl;
    }
    else {
        cout << "Output: False" << endl;
    }

    return 0;
}
