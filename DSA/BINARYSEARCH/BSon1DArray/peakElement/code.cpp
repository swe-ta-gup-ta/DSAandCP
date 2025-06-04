// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int low = 1, high = n - 2;
        auto maxP = max_element(nums.begin(), nums.end()); 
        int maxEleIdx = distance(nums.begin(), maxP);
        int ans = maxEleIdx;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid] > nums[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << findPeakElement(v);
}