// Time Complexity: O(N*W)
// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(int idx, int N, vector<int>& costs, vector<vector<int>> &dp){
    if(idx == 0){
        return N * costs[0];

    }
    if(dp[idx][N] != -1) return dp[idx][N];
    int notTake = 0 + solve(idx - 1, N, costs, dp);
    int take = INT_MIN;
    int rodLength = idx + 1;
    if(rodLength <= N) take = costs[idx] + solve(idx, N - rodLength, costs, dp);

    return dp[idx][N] = max(take, notTake);
}

int rodCutting(int n, int capacity, vector<int>& costs) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n - 1, n, costs, dp);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> wt(n), costs(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> costs[i];
    cout << rodCutting(n, capacity, costs);
    return 0;
}