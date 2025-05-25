// TC = N * 2
// SC = O(6)

#include <iostream>
#include <vector>

using namespace std;


int minStockPrice(vector<int> &prices){
    int n = prices.size();
    vector<int> front1(2, 0);
    vector<int> front2(2, 0);
    vector<int> curr(2, 0);
    
    for(int idx = n - 1; idx >= 0; idx--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy) {
                profit = max(-prices[idx] + front1[0], 0 + front1[1]);
            }
            else{
                profit = max(prices[idx] + front2[1], 0 + front1[0]);
            }
            curr[buy] = profit;
        }
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices);
    return 0;
}