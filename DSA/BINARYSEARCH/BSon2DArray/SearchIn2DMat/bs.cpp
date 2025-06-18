// TC = O(log(n * m))
// SC = O(1)
// https://leetcode.com/problems/search-a-2d-matrix/description/

#include <iostream>
#include <vector>

using namespace std;

bool solve(int n, int m, vector<vector<int>> &mat, int target){
    int low = 0, high = (n * m) - 1;
    while(low <= high) {
        int mid = (low + high ) / 2;
        int row = mid / m;
        int col = mid % m;
        if(mat[row][col] == target){
            return true;
        }
        else if(mat[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {

    int n, m;
    cin >> n >> m;
    int target;
    cin >> target;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> mat[i][j];
    }

    cout << solve(n, m, mat, target);
    return 0;
}