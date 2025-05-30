// TC = O (N * N)
// SC = O(N) + O(N)
// https://leetcode.com/problems/palindrome-partitioning-ii/description/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int isPalin(string s){
    int n = s.size();
    int i = 0, j = n - 1, f = 0;
    while(i <= j) {
        if(s[i] != s[j]) {
            f = 1;
            break;
        }
        i++, j--;
    }
    if(f == 1) return false;
    return true;
}

int solve(int i, string s, int n, vector<int> dp){
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    string temp = "";
    for(int j = i; j < n; j++){
        
        temp += s[j];
        if(isPalin(temp)){
            int cut = 1 + solve(j + 1, s, n, dp);
            ans = min(ans, cut);
        }
    }
    return dp[i] = ans;
}

int minCut(string s){
    int n = s.size();
    if(n == 1) return 0;
    vector<int> dp(n, -1);
    return solve(0, s, n, dp) - 1;
}

int main() {
    string s;
    cin >> s;
    cout << minCut(s);
    return 0;
}