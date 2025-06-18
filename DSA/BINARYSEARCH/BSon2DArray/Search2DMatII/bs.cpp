// TC = O(n + m)
// SC = O(1)
// https://leetcode.com/problems/search-a-2d-matrix-ii/


#include <iostream>
#include <vector>

using namespace std;

bool solve(int n, int m, vector<vector<int>> &mat, int target){
    int row = 0, col = m - 1;
    while(row < n && col >= 0){
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) row++;
        else col--;
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