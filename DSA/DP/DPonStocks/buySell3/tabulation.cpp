// TC = N * 2 * 3
// SC = O(N * 2 * 3)

#include <iostream>
#include <vector>

using namespace std;


int minStockPrice(vector<int> &prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int idx = n - 1; idx >= 0; idx--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                long profit = 0;
                if(buy == 1) {
                    profit = max(-prices[idx] + dp[idx + 1][0][cap], 0 + dp[idx + 1][1][cap]);
                }
                else{
                    profit = max(prices[idx] + dp[idx + 1][1][cap - 1], 0 + dp[idx + 1][0][cap]);
                }
                dp[idx][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices);
    return 0;
}