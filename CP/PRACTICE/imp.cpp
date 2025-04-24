#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to process the string as per given problem statement
string processString(string s) {
    stack<char> binaryStack;  // Stack to store binary values
    vector<int> primeIndexes; // Stores prime indexes

    // Step 1: Identify prime indexed characters and convert them to binary
    for (int i = 0; i < s.length(); i++) {
        if (isPrime(i + 1)) { // Prime index (1-based)
            primeIndexes.push_back(i);
            if (isdigit(s[i])) { // If number, store '0'
                binaryStack.push('0');
            } else { // If letter, store '1'
                binaryStack.push('1');
            }
        }
    }

    // Step 2: Replace original characters at prime indexes with reversed binary values
    for (int idx : primeIndexes) {
        s[idx] = binaryStack.top(); // Pop and replace
        binaryStack.pop();
    }

    return s;
}

int main() {
    string input;

    // Take input from the user
    cout << "Enter the string: ";
    cin >> input;

    // Process and print the modified string
    string output = processString(input);
    cout << "Modified String: " << output << endl;

    return 0;
}
