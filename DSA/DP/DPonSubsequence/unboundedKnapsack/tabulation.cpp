// Time Complexity: O(N*W)
// Reason: There are two nested loops

// Space Complexity: O(N*W)
// Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int unboundedKnapsack(int n, int capacity, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for(int i = 0; i <= capacity; i++) dp[0][i] = ((int)(i/wt[0])) * val[0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= capacity; j++){
            int notTake = 0 + dp[i - 1][j];
            int take = INT_MIN;
            if(wt[i] <= j) take = val[i] + dp[i][j - wt[i]];

            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][capacity];
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