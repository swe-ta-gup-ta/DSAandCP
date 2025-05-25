// TC = 2 ^ n
// SC = O(N)

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int trans, vector<int> &prices, int n, int k){

    if(idx == n || trans == (2 * k)) return 0;

    if(trans % 2 == 0){
        return max(-prices[idx] + solve(idx + 1, trans + 1, prices, n, k), 0 + solve(idx + 1, trans, prices, n, k));
    }
    else {
        return max(prices[idx] + solve(idx + 1, trans + 1, prices, n, k), 0 + solve(idx + 1, trans, prices, n, k));
    }
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    return solve(0, 0, prices, n ,k);
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