// TC = O(N * N)
// SC = O (N)


///This solution used to trace back the prints the longest divisible subset

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void divisibleSet(vector<int>& nums) {
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1), hash(n);
    for(int i = 0; i < n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }

    int ans = -1, lastIndex = -1;

    for(int i = 0; i < n; i++){
        if(dp[i] > ans){
            ans = dp[i];
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
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    divisibleSet(v);
}