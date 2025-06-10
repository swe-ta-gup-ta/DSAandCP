#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;


int solve(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <n ;i++){
        dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        if(i + 3 < n){
            if ((s[i] == s[i + 2]) && (s[i + 1] == s[i + 3]) && (s[i] != s[i + 1])) {
                dp[i + 3] = (dp[i] + dp[i + 3]) % MOD;
            }
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        cout << solve(S) << "\n";
    }

    return 0;
}
