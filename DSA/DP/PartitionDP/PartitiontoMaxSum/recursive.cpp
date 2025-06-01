// TC = exponential
// SC = O(N)
// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(int idx, int n, vector<int> &arr, int k){
    if(idx == n) return 0;
    int len = 0, maxx = INT_MIN, maxAns = INT_MIN;
    for(int j = idx; j < min(idx + k, n); j++){
        len++;
        maxx = max(maxx, arr[j]);
        int sum = len * maxx +  solve(j + 1, n, arr, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    return solve(0, n, arr, k);
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