// TC = O(log(maxEle(arr)) * (n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;


int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (ceil((double)nums[i] / (double)(mid)));
        }
        if(sum <= threshold){
            ans = mid;
            high = mid - 1;
            
            
        }
        else 
            low = mid + 1;
    }
    return ans;
}


int main(){
    int n;
    cin >> n;
    vector<int> bloomDay(n);
    for(int i = 0; i < n; i++) cin >> bloomDay[i];
    int m, k;
    cin >> m >> k;

    cout << smallestDivisor(bloomDay, k, m);
}