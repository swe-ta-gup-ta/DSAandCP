// TC = Exponential
// SC = O(N * N)

#include <bits/stdc++.h>

using namespace std;

int solve(int i, int j, vector<int> &cuts){
    if(i > j) return 0;
    int mini = INT_MAX;
    for(int idx = i; idx <= j; idx++){
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, idx - 1, cuts) + solve(idx + 1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}

int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return solve(1, c, cuts);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << minCost(n, arr);
    return 0;
}