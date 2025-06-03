// TC = O(log(n))
// SC = O(log(n))
// https://leetcode.com/problems/binary-search/description/

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &arr, int target, int low, int high){
    if(low > high) return -1;
    int mid = low + (high - low) / 2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) return solve(arr, target, mid + 1, high);
    else return solve(arr, target, low, mid - 1);
}

int binarySearch(vector<int> &arr, int n, int target){
    int low = 0, high = n - 1;
    return solve(arr, target, low, high);
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
    cout << binarySearch(v, n, target);
}