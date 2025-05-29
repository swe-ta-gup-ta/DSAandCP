// TC = exponential
// SC = O(N * N) + O(N)
// https://leetcode.com/problems/burst-balloons/description/


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(int i, int j, vector<int> &nums){
    if(i > j ) return 0;

    int maxx = INT_MIN;

    for(int idx = i; idx <= j; idx++){
        int cost = nums[i - 1] * nums[idx] * nums[j + 1] + solve(i, idx - 1, nums) + solve(idx + 1, j, nums);
        maxx = max(maxx, cost);
    }
    return maxx;
}

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    return solve(1, n, nums);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << maxCoins(v);
}