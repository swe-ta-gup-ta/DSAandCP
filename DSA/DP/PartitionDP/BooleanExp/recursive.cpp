// TC = exponentional/
// Sc = O(N * N) + O(N)
// https://leetcode.com/problems/parsing-a-boolean-expression/

#include <iostream>
#include <vector>
#include <climits>
#define ll long long
const int mod = 1000000007;

using namespace std;

int solve(int i, int j, int isTrue, string &expression) {
    if (i > j) return 0;
    
    if (i == j) {
        if (isTrue == 1) return expression[i] == 'T' ? 1 : 0;
        else return expression[i] == 'F' ? 1 : 0;
    }
    
    ll ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = solve(i, ind - 1, 1, expression);
        ll lF = solve(i, ind - 1, 0, expression); 
        ll rT = solve(ind + 1, j, 1, expression); 
        ll rF = solve(ind + 1, j, 0, expression); 

        if (expression[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (expression[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return ways;
}

int parseBoolExpr(string expression) {
    int n = expression.size();
    return solve(0, n - 1, 1, expression);
}

int main() {
    string exp;
    cin >> exp;
    cout << parseBoolExpr(exp);
    return 0;
}