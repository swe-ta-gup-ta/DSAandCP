// TC = Exponential = 2 ^ n
// SC = O(bagCapacity)

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(int idx, int capacity, vector<int>& wt, vector<int>& val){
    if(idx == 0){
        return ((int)(capacity/wt[0])) * val[0];
    }

    int notTake = 0 + solve(idx - 1, capacity, wt, val);
    int take = INT_MIN;
    if(wt[idx] <= capacity) take = val[idx] + solve(idx, capacity - wt[idx], wt, val);

    return max(take, notTake);
}

int unboundedKnapsack(int n, int capacity, vector<int>& wt, vector<int>& val) {
    return solve(n - 1, capacity, wt, val);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> val[i];
    cout << unboundedKnapsack(n, capacity, wt, val);
    return 0;
}