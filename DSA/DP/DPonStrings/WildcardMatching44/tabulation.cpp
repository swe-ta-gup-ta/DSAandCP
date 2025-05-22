// Time Complexity: O(N*M)
// Reason: There are two nested loops

// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M’. Stack Space is eliminated.

#include <iostream>
#include <vector>

using namespace std;


bool isMatch(string &s, string &t) {

    int n = s.size(), m = t.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

    dp[0][0] = true;
    for(int i = 1; i <= n; i++) dp[0][i] = false;

    
    for(int j = 1; j <= m; j++){
        bool f = true;
        for(int ii = 1; ii <= j; ii++){
            if(t[ii - 1] != '*') {
                f = false;
                break;
            }
        }
        dp[j][0] = f;
    }

    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == t[j - 1] || t[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(t[j - 1] == '*'){
                return dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else dp[i][j] = false;
        }
    }
    return dp[m][n];
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << isMatch(str1, str2);
    return 0;
}
