// TC = O(log(n))
// SC = O(1)
// https://leetcode.com/problems/binary-search/description/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int n, int target){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        else if(target < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
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