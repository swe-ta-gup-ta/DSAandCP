#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int j, vector<int> &arr, vector<vector<int>> dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int minn = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        minn = min(minn, steps);
    }
    return dp[i][j] = minn;
}

int matrixChainMultiplication(vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(1, n - 1, arr, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << matrixChainMultiplication(arr, n);
    return 0;
}