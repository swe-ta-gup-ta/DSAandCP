#include<bits/stdc++.h>

using namespace std;

///1. Normal recursive approach

// int solve(int idx, vector<int> &wt, vector<int> &cost, int cap){
//     if(idx == 0) {
//         if(wt[0] <= cap) return cost[idx];
//         else return 0;
//     }
//     if(cap == 0) return 0;
//     int npick = 0 + solve(idx - 1, wt, cost, cap);
//     int pick = INT_MIN;
//     if(wt[idx] <= cap){
//         pick = cost[idx] + solve(idx - 1, wt, cost, cap - wt[idx]);
//     }
//     return max(npick, pick);
// }

// int main(){
//     int n;
//     cin >> n;
//     int capacity;
//     cin >> capacity;
//     vector<int>wt(n), cost(n);
//     for(int i = 0; i < n; i++) cin >> wt[i];
//     for(int i = 0; i < n; i++) cin >> cost[i];
//     cout << solve(n - 1, wt, cost, capacity); 
//     return 0;
// }

// 2. memoization  using dp()

// int solve(int idx, vector<int> &wt, vector<int> &cost, int cap, vector<vector<int>> &dp){
//     if(idx == 0) {
//         if(wt[0] <= cap) return cost[idx];
//         else return 0;
//     }
//     if(dp[idx][cap] != -1) return dp[idx][cap];
//     int npick = 0 + solve(idx - 1, wt, cost, cap, dp);
//     int pick = INT_MIN;
//     if(wt[idx] <= cap){
//         pick = cost[idx] + solve(idx - 1, wt, cost, cap - wt[idx], dp);
//     }
//     return dp[idx][cap] = max(npick, pick);
// }

// int main(){
//     int n;
//     cin >> n;
//     int capacity;
//     cin >> capacity;
//     vector<int>wt(n), cost(n);
//     for(int i = 0; i < n; i++) cin >> wt[i];
//     for(int i = 0; i < n; i++) cin >> cost[i];
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
//     cout << solve(n - 1, wt, cost, capacity, dp); 
//     return 0;
// }


// 3. tabulation - dp (buttom - up approach)

int solve(int idx, vector<int> &wt, vector<int> &cost, int cap, vector<vector<int>> &dp){
    if(idx == 0) {
        if(wt[0] <= cap) return cost[idx];
        else return 0;
    }
    if(dp[idx][cap] != -1) return dp[idx][cap];
    int npick = 0 + solve(idx - 1, wt, cost, cap, dp);
    int pick = INT_MIN;
    if(wt[idx] <= cap){
        pick = cost[idx] + solve(idx - 1, wt, cost, cap - wt[idx], dp);
    }
    return dp[idx][cap] = max(npick, pick);
}

int main(){
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    vector<int>wt(n), cost(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> cost[i];
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for(int i = wt[0]; i <= capacity; i++) dp[0][i] = cost[0];
    for(int i  = 1; i < n; i++){
        for(int j = 0; j <= capacity; j++){
            int npick = 0 + dp[i - 1][j];
            int pick = INT_MIN;
            if(wt[i] <= j){
                pick = cost[i] + dp[i - 1][j - wt[i]];
            }
            dp[i][j] = max(npick, pick);
        }
    }
    cout << dp[n - 1][capacity];
    return 0;
}