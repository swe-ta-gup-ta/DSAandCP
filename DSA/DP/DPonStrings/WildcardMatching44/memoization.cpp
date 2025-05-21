///recursive TC= exponential - very big 
//problem link = https://leetcode.com/problems/wildcard-matching/description/

#include <iostream>
#include <vector>

using namespace std;

bool solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    
    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    
    if(i < 0 && j >= 0) {
        for(int ii = 0; ii < j; ii++){
            if(t[ii] != '*') return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i] == t[j] || t[j] == '?'){
        return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
    }
    if(t[j] == '*'){
        return dp[i][j] = solve(s, t, i - 1, j, dp) || solve(s, t, i, j - 1, dp);
    }
    return dp[i][j] = false;
}

int isMatch(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(s, t, n - 1, m - 1, dp);
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << isMatch(str1, str2);
    return 0;
}
