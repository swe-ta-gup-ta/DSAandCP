// TC = O(N) * O(K)
// SC = O(N) + O(N)
// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(int idx, int n, vector<int> &arr, int k, vector<int> &dp){
    if(idx == n) return 0;
    if(dp[idx] != -1) return dp[idx];
    int len = 0, maxx = INT_MIN, maxAns = INT_MIN;
    for(int j = idx; j < min(idx + k, n); j++){
        len++;
        maxx = max(maxx, arr[j]);
        int sum = len * maxx +  solve(j + 1, n, arr, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[idx] = maxAns;

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, n, arr, k, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    cout << maxSumAfterPartitioning(v, k);
    return 0;
}