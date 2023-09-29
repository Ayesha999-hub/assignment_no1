#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;
int main() {
    string text ;
    cout << "enter the string : ";
    cin >> text;

    // Create a set to store unique words
    set<string> uniqueWords;

    // Tokenize the input string and extract unique words
    istringstream iss(text);
    string word;
    while (iss >> word) {
        // Remove punctuation and convert to lowercase if needed
        while (!word.empty() && !isalnum(word.back())) {
            word.pop_back();
        }
        // Convert to lowercase
        

        uniqueWords.insert(word);
    }

    // Display the unique words and their sizes
    for (const string& uniqueWord : uniqueWords) {
        cout << "Word: " << uniqueWord << ", Size: " << uniqueWord.size() << endl;
    }

    return 0;
}
