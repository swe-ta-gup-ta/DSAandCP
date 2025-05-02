// Time Complexity: O(N*M)
// Reason: There are two nested loops

// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.

//If we know the longest palindromic sub-sequence is x
// and the length of the string is n then, what is the answer to this problem? 
// It is n - x as we need n - x insertions to make the remaining 
// characters also palindrome.

// same as that of finding longest palindromic subsequence

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
int minInsertions(string s) {
    int len = longestPalindromeSubseq(s);
    int n = s.size();
    return n - len;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
    return 0;
}
