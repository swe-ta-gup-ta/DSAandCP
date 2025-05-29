// TC = O(N * N)
// SC = O(N * N) + O(N)
// https://leetcode.com/problems/burst-balloons/description/


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
    if(i > j ) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int maxx = INT_MIN;

    for(int idx = i; idx <= j; idx++){
        int cost = nums[i - 1] * nums[idx] * nums[j + 1] + solve(i, idx - 1, nums, dp) + solve(idx + 1, j, nums, dp);
        maxx = max(maxx, cost);
    }
    return dp[i][j] = maxx;
}

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            if(i > j ) continue;
            int maxx = INT_MIN;
            for(int idx = i; idx <= j; idx++){
                int cost = nums[i - 1] * nums[idx] * nums[j + 1] + dp[i][idx - 1] + dp[idx + 1][j];
                maxx = max(maxx, cost);
            }
            dp[i][j] = maxx;
        }
    }

    return dp[1][n];
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << maxCoins(v);
}