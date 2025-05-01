// Time Complexity: O(N*M)
// Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.

// Space Complexity: O(N*M) + O(N+M)
// Reason: We are using an auxiliary recursion stack space(O(N+M))
//(see the recursive tree, in the worst case, we will go till N+M calls at a time) 
// and a 2D array ( O(N*M)).

#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){

    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
    }
    else{
        return dp[i][j] = max(0 + solve(i -1, j, s1, s2, dp), 0 + solve(i, j - 1, s1, s2, dp));
    }
}

// doing by shifting of index => then dp must be 
// vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
// and call should be return solve(n, m, text1, text2, dp);

// int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){

//     if(i == 0 || j == 0) return 0;

//     if(dp[i][j] != -1) return dp[i][j];

//     if(s1[i - 1] == s2[j - 1]){
//         return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
//     }
//     else{
//         return dp[i][j] = max(0 + solve(i -1, j, s1, s2, dp), 0 + solve(i, j - 1, s1, s2, dp));
//     }
// }

int LCS(string text1, string text2){
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, text1, text2, dp);
}

int main(){
    string s1, s2;
    cout << LCS(s1, s2);
    return 0;
}