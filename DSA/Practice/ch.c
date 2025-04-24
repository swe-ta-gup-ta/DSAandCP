#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string smallestPalindromicPermutation(string s) {
    vector<int> freq(26, 0);

    // Count frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    string half = "", center = "";

    // Build half of the palindrome and determine the center character if needed
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            center = string(1, 'a' + i);
            freq[i]--;
        }
        half += string(freq[i] / 2, 'a' + i);
    }

    string rev_half = half;
    reverse(rev_half.begin(), rev_half.end());

    return half + center + rev_half;
}

int main() {
    // Example test cases
    vector<string> test_cases = {"z", "babab", "daccad"};

    for (const string& s : test_cases) {
        cout << "Input: " << s << endl;
        cout << "Output: " << smallestPalindromicPermutation(s) << endl << endl;
    }

    return 0;
}
