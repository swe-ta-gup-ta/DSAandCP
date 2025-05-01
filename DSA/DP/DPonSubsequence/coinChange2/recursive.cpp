#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int amount, vector<int> & coins) {
    if(idx == 0){
        return (amount % coins[0] == 0);
    }

    int notTake = solve(idx - 1, amount, coins);
    int take = 0;
    if(coins[idx] <= amount) take = solve(idx, amount - coins[idx], coins);
    
    return take + notTake;
}


int change(int amount, vector<int>& coins, int n) {
    return solve(n - 1, amount, coins);
}

int main(){
    int n, amount;
    cin >> n >> amount;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << change(amount, arr, n);
    return 0;
}


// TC = exponential (can be greater can 2 ^ n)
// SC = (greater than O(n) => O(target))