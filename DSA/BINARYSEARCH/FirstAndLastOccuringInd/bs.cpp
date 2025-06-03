// TC = 2 * O(log(n))
// SC = O(1)
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> firstAndLastOccurence(vector<int> &arr, int n, int target){
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    if(lb == n || arr[lb] != target) return {-1, -1};
    return {lb, ub - 1};
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
    vector<int> x = firstAndLastOccurence(v, n, target);
    for(auto i : x) cout << i << " ";
}