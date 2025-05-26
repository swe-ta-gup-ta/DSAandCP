// TC = O(N * N)
// SC = O (N * N) + O (N)

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int prev, vector<int> &v, vector<vector<int>> &dp) {

    if(idx == v.size()) return 0;
    if(dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
    int len = 0 + solve(idx + 1, prev, v, dp);
    if(prev == -1 || v[idx] > v[prev]){
        len = max(len, 1 + solve(idx + 1, idx, v, dp));
    }
    return dp[idx][prev + 1] = len;
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(0, -1, nums, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << lengthOfLIS(v) << endl;
}