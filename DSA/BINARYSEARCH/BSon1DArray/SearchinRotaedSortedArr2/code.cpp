// TC = O(log(n))
// SC = O(1)
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << findMin(v);
}