// TC = N * 2
// SC = O(N * 2)

#include <iostream>
#include <vector>

using namespace std;


int minStockPrice(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for(int idx = n - 1; idx >= 0; idx--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy) {
                profit = max(-prices[idx] + dp[idx + 1][0], 0 + dp[idx + 1][1]);
            }
            else{
                profit = max(prices[idx] + dp[idx + 2][1], 0 + dp[idx + 1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices);
    return 0;
}