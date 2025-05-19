///memoized TC= O(N * M) SC = O( N * M) + O(N + M)

#include <iostream>
#include <vector>

using namespace std;

int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){

    if(j < 0) return i + 1; 
    if(i < 0) return j + 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) {
        return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
    }
    int insert = 1 + solve(s, t, i, j - 1, dp);
    int delte = 1 + solve(s, t, i - 1, j, dp);
    int replace = 1 + solve(s, t, i - 1, j - 1, dp);
    return dp[i][j] = min(insert, min(delte, replace));
}

int minDistance(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(s, t, n - 1, m - 1, dp);
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << minDistance(str1, str2);
    return 0;
}