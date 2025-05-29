// Time Complexity: O(N*N*2 * N) ~ O(N3) There are a total of 2*N2 no. of states.
// And for each state, we are running a partitioning loop roughly for N times.
// Space Complexity: O(2*N2) + Auxiliary stack space of O(N), 2*N2 for the dp array we are using.

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    if (i > j) return 0;
    
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);  
        ll lF = f(i, ind - 1, 0, exp, dp);
        ll rT = f(ind + 1, j, 1, exp, dp); 
        ll rF = f(ind + 1, j, 0, exp, dp); 

        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else { 
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}

int main() {
    string exp;
    cin >> exp;
    cout << evaluateExp(exp);
    return 0;
}


