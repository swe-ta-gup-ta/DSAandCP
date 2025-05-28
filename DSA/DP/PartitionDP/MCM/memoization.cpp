// TC = O(N * N) * N
// SC = O(N*N) + O(N)

#include <bits/stdc++.h>

using namespace std;

int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int mcm(vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(1, n - 1, arr, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << mcm(arr, n);
    return 0;
}