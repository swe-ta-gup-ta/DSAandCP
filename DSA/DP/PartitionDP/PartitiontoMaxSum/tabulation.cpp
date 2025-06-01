// TC = O(N) * O(K)
// SC = O(N)
// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for(int idx = n - 1; idx >= 0; idx--){
        int len = 0, maxx = INT_MIN, maxAns = INT_MIN;
        for(int j = idx; j < min(idx + k, n); j++){
            len++;
            maxx = max(maxx, arr[j]);
            int sum = len * maxx + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[idx] = maxAns;
    }
    return dp[0];
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