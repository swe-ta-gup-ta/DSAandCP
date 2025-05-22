// Time Complexity: O(N*M)
// Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.

// Space Complexity: O(N*M) + O(N+M)
// Reason: We are using a recursion stack space(O(N+M)) and a 2D array ( O(N*M)).


#include <iostream>
#include <vector>

using namespace std;


bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;

    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << isMatch(str1, str2);
    return 0;
}
