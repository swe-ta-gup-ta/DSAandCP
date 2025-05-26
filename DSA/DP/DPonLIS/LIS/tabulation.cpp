// TC = O(N * N)
// SC = O (N * N)

#include <iostream>
#include <vector>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int idx = n - 1; idx >= 0; idx--){
        for(int prev = idx - 1; prev >= -1; prev--){
            int len = 0 + dp[idx + 1][prev + 1];
            if(prev == -1 || nums[idx] > nums[prev]){
                len = max(len, 1 + dp[idx + 1][idx + 1]);
            }
            dp[idx][prev + 1] = len;
        }
    }
    return dp[0][0  ];
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << lengthOfLIS(v) << endl;
}