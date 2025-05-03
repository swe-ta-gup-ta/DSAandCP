// Time Complexity: O(N*M)
// Reason: There are two nested loops

// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.

// We are given two strings ‘S1’ and ‘S2’. We need to return their shortest common
// supersequence. A supersequence is defined as the string which contains both the
// strings S1 and S2 as subsequences.

//same as that of LCS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int shortestCommonSupersequence(string text1, string text2){
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

    //Printing the shortestCommonSupersequence string

    int len = dp[n][m];
    int res = n + m - len;
    int i = n, j = m;
    string ans = "";

    while(i > 0 && j > 0){
        if(text1[i - 1] == text2[j - 1]) {
            ans += text1[i - 1];
            i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j -1]){
            ans += text1[i - 1];
            i--;
        }
        else {
            ans += text2[j - 1];
            j--;
        }
    }
    while(j > 0) ans+= text2[j -1], j--;
    while(i > 0) ans+= text1[i -1], i--;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return res;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << shortestCommonSupersequence(s1, s2);
    return 0;
}