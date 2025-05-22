#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int mn = prices[0];
    int maxProfit = 0;
    for(int i = 1; i < n; i++) {
        int cost = prices[i] - mn;
        maxProfit = max(maxProfit, cost);
        mn = min(mn, prices[i]);
    }
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << maxProfit(prices);
    return 0;
}