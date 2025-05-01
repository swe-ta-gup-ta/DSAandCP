// Time Complexity: O(N*W)
// Reason: There are two nested loops

// Space Complexity: O(N*W)
// Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int rodCutting(int n, int capacity, vector<int>& costs) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for(int i = 0; i <= n; i++){
        dp[0][i] = i * costs[0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            int notTake = 0 + dp[i - 1][j];
            int take = INT_MIN;
            int rodLength = i + 1;
            if(rodLength <= j) take = costs[i] + dp[i][j - rodLength];

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
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