// TC = O(N * N)
// SC = O (N)

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
///This solution used to trace back the LIS 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int numberOfLIS(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> dp(n, 1), cnt(n, 1);
    int maxx = 1;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }
            else if(nums[prev] < nums[i] && 1 + dp[prev]== dp[i]) cnt[i] += cnt[prev];
        }
        maxx = max(maxx, dp[i]);
    }

    int nos = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxx) nos += cnt[i];
    }
    
    return nos;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << numberOfLIS(v) << endl;
}