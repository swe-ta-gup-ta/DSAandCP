///memoized TC= O(N * M) SC = O( N * M) + O(N + M)

#include <iostream>
#include <vector>

using namespace std;

int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    
    if(j < 0) return 1; 
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) {
        return dp[i][j] = solve(s, t, i - 1, j - 1, dp) + solve(s, t, i - 1, j, dp);
    }
    else return dp[i][j] = solve(s, t, i - 1, j, dp);
}

int numDistinct(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(s, t, n - 1, m - 1, dp);
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << numDistinct(str1, str2);
    return 0;
}