// TC = O(log(n))
// SC = O(1)

//answer will be the index of minimum element

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int countRotated(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX, index = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[low] <= nums[mid]){
            if(nums[low] < ans){
                index = low;
                ans = nums[low];
            }
            low = mid + 1;
        }
        else{
            if(nums[mid] < ans){
                index = mid;
                ans = nums[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << countRotated(v);
}