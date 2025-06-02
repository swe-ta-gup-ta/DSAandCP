// Time Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
// Reason: We are basically traversing a 2D matrix with N rows and M columns.

// Space Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
// Reason: We are using a 2D dp array with N rows and M columns.
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#include <iostream>
#include <vector>

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
    for(int i = 0; i < n; i++) dp[i][0] = matrix[i][0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0) dp[i][j] = 0;
            else{
                dp[i][j] = 1 + min(dp[i- 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // sum += dp[i][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }

    cout << countSquares(v);
}