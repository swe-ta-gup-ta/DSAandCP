// TC = N * 2 * k
// SC = O(N * 2 * k)

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(k * 2 + 1, 0));
    
    for(int idx = n- 1; idx >= 0; idx--) {
        for(int trans = (2 * k) - 1; trans >= 0; trans--){
            if(trans % 2 == 0){
                dp[idx][trans] = max(-prices[idx] + dp[idx + 1][trans + 1], 0 + dp[idx + 1][trans]);
            }
            else {
                dp[idx][trans] = max(prices[idx] + dp[idx+1][trans+1], 0 + dp[idx +1][trans]);
            }
        }
    }
    return dp[0][0];
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