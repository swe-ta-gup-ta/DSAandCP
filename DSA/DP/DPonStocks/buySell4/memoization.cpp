// TC = N * 2 * k
// SC = O(N * 2 * k) + O (N)

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int trans, vector<int> &prices, int n, int k, vector<vector<int>> &dp){

    if(idx == n || trans == (2 * k)) return 0;
    if(dp[idx][trans] != -1) return dp[idx][trans];
    if(trans % 2 == 0){
        return dp[idx][trans] = max(-prices[idx] + solve(idx + 1, trans + 1, prices, n, k, dp), 0 + solve(idx + 1, trans, prices, n, k, dp));
    }
    else {
        return dp[idx][trans] = max(prices[idx] + solve(idx + 1, trans + 1, prices, n, k, dp), 0 + solve(idx + 1, trans, prices, n, k, dp));
    }
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(k * 2, -1));
    return solve(0, 0, prices, n ,k, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    int k;
    cin >> k;
    cout << maxProfit(k, prices);
    return 0;
}