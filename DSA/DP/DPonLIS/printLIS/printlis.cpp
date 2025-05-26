// TC = O(N * N)
// SC = O (N)


///This solution used to trace back the LIS 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> dp(n, 1), hash(n);
    int maxx = 1;
    int lastIndex = 0;
    for(int i = 0; i < n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxx){
            maxx = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(), temp.end());

    for(auto i : temp) cout << i << " ";
    
    return maxx;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << lengthOfLIS(v) << endl;
}