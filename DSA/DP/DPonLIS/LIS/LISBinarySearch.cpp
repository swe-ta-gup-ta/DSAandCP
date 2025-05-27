// TC = (N log(N))
// SC = O(N)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i = 1; i < n; i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }
    return temp.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << lengthOfLIS(v) << endl;
}