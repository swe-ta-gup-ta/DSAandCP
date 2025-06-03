// TC = 2 * O(log(n))
// SC = O(1)
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstOccurence(vector<int> &arr, int n, int target){
    int low = 0, high = n - 1, first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    } 
    return first;
}

int lastOccurence(vector<int> &arr, int n, int target){
    int low = 0, high = n - 1, last = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    } 
    return last;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int first = firstOccurence(nums, n, target);
    if(first == -1) return {-1, -1};
    int last = lastOccurence(nums, n, target);
    return {first, last};
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int target;
    cin >> target;
    vector<int> x = searchRange(v, target);
    for(auto i : x) cout << i << " ";
}