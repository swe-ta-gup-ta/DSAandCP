///tabulation TC= O(N * M) SC = O( N * M)

#include <iostream>
#include <vector>

using namespace std;

int minDistance(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            }
            else{ 
                int insert = 1 + dp[i][j -1];
                int delte = 1 + dp[i - 1][j]; 
                int replace = 1 + dp[i - 1][j - 1]; 
                dp[i][j] = min(insert, min(delte, replace));
            }
        }
    }
    return dp[n][m];
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << minDistance(str1, str2);
    return 0;
}