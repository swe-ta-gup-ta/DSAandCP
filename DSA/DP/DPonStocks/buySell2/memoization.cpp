// TC = N * 2
// SC = O(N * 2) + O (N)

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int buy, vector<int> &prices, int profit, vector<vector<int>> &dp) {
    if(idx == prices.size()){
        return 0;
    }
    if(dp[idx][buy] != -1) return dp[idx][buy];
    if(buy) {
        profit = max(-prices[idx] + solve(idx + 1, 0, prices, profit, dp), 0 + solve(idx + 1, 1, prices, profit, dp));
    }
    else{
        profit = max(prices[idx] + solve(idx + 1, 1 , prices, profit, dp), 0 + solve(idx + 1, 0, prices, profit, dp));
    }
    return dp[idx][buy] = profit;
}

int minStockPrice(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, 0, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices);
    return 0;
}