#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparison function to sort pairs based on the second element
bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> pairs = {{1, 5}, {2, 1}, {3, 3}};

    // Sort the vector of pairs using the custom comparison function
    sort(pairs.begin(), pairs.end(), comparePairs);

    // Print the sorted vector of pairs
    for (const auto& pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    return 0;
}