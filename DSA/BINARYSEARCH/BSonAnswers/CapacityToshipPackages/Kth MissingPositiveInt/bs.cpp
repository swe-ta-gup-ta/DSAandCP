// TC = O(log(N))
// SC = O(1)
// https://leetcode.com/problems/kth-missing-positive-number/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) /2;
        int noOfmissing = arr[mid] - (mid + 1);
        if(noOfmissing < k) {
            low = mid + 1;
        }
        else high = mid - 1;
    } 
    return low + k;
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;

    cout << findKthPositive(v, k);
}