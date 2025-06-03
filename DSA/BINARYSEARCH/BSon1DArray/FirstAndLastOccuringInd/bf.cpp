// TC = O(N)
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &arr, int n, int target){
    int first = -1, last = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            if(first == -1) first = i;
            last = i;
        }
    }
    cout << first << " " << last << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;  i < n; i++) cin >> v[i];
    int target;
    cin >> target;
    solve(v, n, target);
    return 0;
}