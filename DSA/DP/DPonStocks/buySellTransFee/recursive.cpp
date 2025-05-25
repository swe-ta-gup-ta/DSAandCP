// TC = 2 ^ n
// SC = O(N)
///VVVV important question

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int buy, vector<int> &prices, int profit, int fee) {
    if(idx == prices.size()){
        return 0;
    }

    if(buy) {
        profit = max(-prices[idx] + solve(idx + 1, 0, prices, profit, fee), 0 + solve(idx + 1, 1, prices, profit, fee));
    }
    else{
        profit = max(prices[idx] - fee + solve(idx + 1, 1 , prices, profit, fee), 0 + solve(idx + 1, 0, prices, profit, fee));
    }
    return profit;
}

int minStockPrice(vector<int> &prices, int fee){
    return solve(0, 1, prices, 0, fee);
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    int fee;
    cin >> fee;
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices, fee);
    return 0;
}