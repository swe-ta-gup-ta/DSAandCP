#include<bits/stdc++.h>
using namespace std;
//count subsets with sum = k

// 1. recursive approach
int solve(int idx, vector<int> arr, int sum){
    if(idx == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        else if(sum == 0 || arr[0] == sum) return 1;
        return 0;
    }
    int ntake = solve(idx - 1, arr, sum);
    int take = 0;
    if(arr[idx] <= sum) take = solve(idx - 1, arr, sum - arr[idx]);
    return take + ntake;
}

int perfectSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    return solve(n - 1, arr, target);
}

// 2. Memoization

int solve(int idx, vector<int> arr, int sum, vector<vector<int>> dp){
    if(idx == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        else if(sum == 0 || arr[0] == sum) return 1;
        return 0;
    }
    if(dp[idx][sum] != -1) return dp[idx][sum];
    int ntake = solve(idx - 1, arr, sum, dp);
    int take = 0;
    if(arr[idx] <= sum) take = solve(idx - 1, arr, sum - arr[idx], dp);
    return dp[idx][sum] = take + ntake;
}

int perfectSum(vector<int>& arr, int sum) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(n - 1, arr, sum, dp);
}

// 3. Tabulation (buttom - up)

int perfectSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;
    for(int i = 1; i < n; i++){
        for(int s = 0; s <= target; s++){
            int ntake = dp[i - 1][s];
            int take = 0;
            if(arr[i] <= target) take = dp[i - 1][s - arr[i]];
           dp[i][target] = take + ntake;
        }
    }
    return dp[n - 1][target];
}


// 4. space optimisation
int perfectSum(vector<int>& arr, int sum) {
    // code here
    int n = arr.size();
    vector<int> prev(n, 0), curr(sum + 1);
    prev[0] = curr[0] = 1;
    for(int i = 1; i < n; i++){
        for(int s = 0; s <= sum; s++){
            int ntake = prev[s];
            int take = 0;
            if(arr[i] <= sum) take = prev[s - arr[i]];
            curr[sum] = take + ntake;
        }
        curr = prev;
    }
    return prev[n - 1];
} 


