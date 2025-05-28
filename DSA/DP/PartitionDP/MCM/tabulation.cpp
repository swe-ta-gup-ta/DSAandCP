// TC = O(N * N) * N
// SC = O(N*N)

#include <bits/stdc++.h>

using namespace std;

int mcm(vector<int> &arr, int n){
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for(int i = n - 1; i >= 1; i--){
        for(int j = i + 1; j < n; j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if(steps < mini) mini = steps;
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << mcm(arr, n);
    return 0;
}