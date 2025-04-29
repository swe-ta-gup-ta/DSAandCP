#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Custom hash for pair<int, int>
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int coveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_set<pair<int, int>, pair_hash> buildingSet;
        
        for (auto& b : buildings) {
            buildingSet.insert({b[0], b[1]});
        }
        
        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            
            bool hasLeft = false, hasRight = false, hasAbove = false, hasBelow = false;
            
            // Check left
            for (int j = y - 1; j >= 1; --j) {
                if (buildingSet.count({x, j})) {
                    hasLeft = true;
                    break;
                }
            }
            
            // Check right
            for (int j = y + 1; j <= n; ++j) {
                if (buildingSet.count({x, j})) {
                    hasRight = true;
                    break;
                }
            }
            
            // Check above
            for (int i = x - 1; i >= 1; --i) {
                if (buildingSet.count({i, y})) {
                    hasAbove = true;
                    break;
                }
            }
            
            // Check below
            for (int i = x + 1; i <= n; ++i) {
                if (buildingSet.count({i, y})) {
                    hasBelow = true;
                    break;
                }
            }
            
            if (hasLeft && hasRight && hasAbove && hasBelow) {
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    int n1 = 3;
    vector<vector<int>> buildings1 = {{1,2},{2,2},{3,2},{2,1},{2,3}};
    cout << sol.coveredBuildings(n1, buildings1) << endl; // Output: 1
    
    int n2 = 3;
    vector<vector<int>> buildings2 = {{1,1},{1,2},{2,1},{2,2}};
    cout << sol.coveredBuildings(n2, buildings2) << endl; // Output: 0
    
    int n3 = 5;
    vector<vector<int>> buildings3 = {{1,3},{3,2},{3,3},{3,5},{5,3}};
    cout << sol.coveredBuildings(n3, buildings3) << endl; // Output: 1

    return 0;
}
