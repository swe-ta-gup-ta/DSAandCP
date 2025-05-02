// Time Complexity: O(N*M)
// Reason: There are two nested loops

// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(string text1, string text2){
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= m; j++) dp[0][j] = 0;

    for(int i  = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return LCS(s, t);
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
    return 0;
}
