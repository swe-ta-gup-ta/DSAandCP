// TC = O(n * log(m))
// SC = O(1)
// https://leetcode.com/problems/search-a-2d-matrix/description/


#include <iostream>
#include <vector>

using namespace std;

bool solve(int n, int m, vector<vector<int>> &mat, int target){
    for(int i = 0; i < n; i++){
        if((mat[i][0] <= target) && (target <= mat[i][m - 1])) {
            
            int eleIdx = lower_bound(mat[i].begin(), mat[i].end(), target) - mat[i].begin();
            if(eleIdx == (m)) return false;
            if(mat[i][eleIdx] == target) return true;
        }
    }
    return false;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> mat[i][j];
    }
    int target;
    cin >> target;

    cout << solve(n, m, mat, target);
    return 0;
}