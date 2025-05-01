// Time Complexity: O(N*W)
// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(int idx, int capacity, vector<int>& wt, vector<int>& val, vector<vector<int>> dp){
    if(idx == 0){
        return ((int)(capacity/wt[0])) * val[0];
    }
    
    if(dp[idx][capacity] != -1) return dp[idx][capacity];
    
    int notTake = 0 + solve(idx - 1, capacity, wt, val, dp);
    int take = INT_MIN;
    if(wt[idx] <= capacity) take = val[idx] + solve(idx, capacity - wt[idx], wt, val, dp);

    return dp[idx][capacity ] = max(take, notTake);
}

int unboundedKnapsack(int n, int capacity, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return solve(n - 1, capacity, wt, val, dp);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> val[i];
    cout << unboundedKnapsack(n, capacity, wt, val);
    return 0;
}