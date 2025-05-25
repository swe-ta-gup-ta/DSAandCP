// TC = N * 2 * 3
// SC = O(N * 2 * 3) + O (N)

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int buy, vector<int> &prices, int profit, vector<vector<vector<int>>> &dp, int cap) {
    if(cap == 0) return 0;
    if(idx == prices.size()){
        return 0;
    }
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    if(buy) {
        profit = max(-prices[idx] + solve(idx + 1, 0, prices, profit, dp, cap), 0 + solve(idx + 1, 1, prices, profit, dp, cap));
    }
    else{
        profit = max(prices[idx] + solve(idx + 1, 1 , prices, profit, dp, cap - 1), 0 + solve(idx + 1, 0, prices, profit, dp, cap));
    }
    return dp[idx][buy][cap] = profit;
}

int minStockPrice(vector<int> &prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, prices, 0, dp, 2);
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices);
    return 0;
}