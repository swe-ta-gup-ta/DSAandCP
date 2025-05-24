// TC = N * 2
// SC = O(2)

#include <iostream>
#include <vector>

using namespace std;


int minStockPrice(vector<int> &prices){
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);

    ahead[0] = ahead[1] = 0;
    for(int idx = n - 1; idx >= 0; idx--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy) {
                profit = max(-prices[idx] + ahead[0], 0 + ahead[1]);
            }
            else{
                profit = max(prices[idx] + ahead[1], 0 + ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices);
    return 0;
}