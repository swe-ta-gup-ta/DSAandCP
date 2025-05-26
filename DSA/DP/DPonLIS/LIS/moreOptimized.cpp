// TC = O(N * N)
// SC = O (N)


///This solution used to trace back the LIS 

#include <iostream>
#include <vector>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> dp(n, 1);
    int maxx = 1;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxx = max(maxx, dp[i]);
    }
    return maxx;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << lengthOfLIS(v) << endl;
}