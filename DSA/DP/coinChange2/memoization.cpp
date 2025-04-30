#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int amount, vector<int> & coins, vector<vector<int>> &dp) {
    if(idx == 0){
        return (amount % coins[idx] == 0);
    }

    if(dp[idx][amount] != -1) return dp[idx][amount];

    int notTake = solve(idx - 1, amount, coins, dp);
    int take = 0;
    if(coins[idx] <= amount) take =  solve(idx, amount - coins[idx], coins, dp);
    
    return dp[idx][amount] = take + notTake;
}


int change(int amount, vector<int>& coins, int n) {

    vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
    return solve(n - 1, amount, coins, dp);

}

int main(){
    int n, amount;
    cin >> n >> amount;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << change(amount, arr, n);
    return 0;
}


// TC = O(n * target)
// SC = O(n * target) + O(target)