// TC = N * 2 * k
// SC = O(2 * k)

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();

    vector<int> after(k * 2 + 1, 0);
    vector<int> curr(k * 2 + 1, 0);
    
    for(int idx = n- 1; idx >= 0; idx--) {
        for(int trans = (2 * k) - 1; trans >= 0; trans--){
            if(trans % 2 == 0){
                curr[trans] = max(-prices[idx] + after[trans + 1], 0 + after[trans]);
            }
            else {
                curr[trans] = max(prices[idx] + after[trans + 1], 0 + after[trans]);
            }
        }
        after = curr;
    }
    return after[0];
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