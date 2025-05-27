// TC = O(N * N)
// SC = O (N)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int longestBitcoinSubs(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> dp(n, 1);
    int maxx = -1;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
            }
        }
    }

    vector<int> dp2(n, 1);
    int lastIndex = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int prev = n - 1; prev > i; prev--){
            if(nums[prev] < nums[i] && 1 + dp2[prev] > dp2[i]){
                dp2[i] = 1 + dp2[prev];
            }
        }
    }
    for(int i = 0; i < n; i++){
        maxx = max(maxx, dp[i] + dp2[i] - 1);
    }
    return maxx;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << longestBitcoinSubs(v) << endl;
}