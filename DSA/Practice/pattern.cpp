#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::pair<int, int>> pairs = {{1, 2}, {3, 4}, {1, 2}, {5, 6}, {1, 2}};
    std::pair<int, int> target_pair = {1, 2};

    // Use std::count to count occurrences of the target pair
    int count = std::count(pairs.begin(), pairs.end(), target_pair);

    std::cout << "The pair (" << target_pair.first << ", " << target_pair.second
              << ") appears " << count << " times." << std::endl;

    return 0;
}