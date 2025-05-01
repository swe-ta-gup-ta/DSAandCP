// Time Complexity: O(N*M)
// Reason: There are two nested loops

// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.

#include <iostream>
#include <vector>

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

    //Printing the LCS string

    int len = dp[n][m];
    int idx = len - 1;
    int i = n, j = m;
    string ans = "";
    for(int i = 0; i < len; i++) ans+= '$';

    while(i > 0 && j > 0){
        if(text1[i - 1] == text2[j - 1]) {
            ans[idx] = text1[i - 1];
            idx--, i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j -1]){
            i--;
        }
        else j--;
    }
    cout << ans << endl;

    return dp[n][m];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
    return 0;
}


// example
// abcde
// bdqek
// 0 0 0 0 0 0 
// 0 0 0 0 0 0 
// 0 1 1 1 1 1 
// 0 1 1 1 1 1 
// 0 1 2 2 2 2 
// 0 1 2 2 3 3 
// 3