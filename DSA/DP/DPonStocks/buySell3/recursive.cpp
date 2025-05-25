// TC = 2 ^ n
// SC = O(N)

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int buy, vector<int> &prices, int profit, int cap) {
    if(cap == 0) return 0;
    if(idx == prices.size()){
        return 0;
    }

    if(buy) {
        profit = max(-prices[idx] + solve(idx + 1, 0, prices, profit, cap), 0 + solve(idx + 1, 1, prices, profit, cap));
    }
    else{
        profit = max(prices[idx] + solve(idx + 1, 1 , prices, profit, cap -1), 0 + solve(idx + 1, 0, prices, profit, cap));
    }
    return profit;
}

int minStockPrice(vector<int> &prices){
    return solve(0, 1, prices, 0, 2);
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << minStockPrice(prices);
    return 0;
}