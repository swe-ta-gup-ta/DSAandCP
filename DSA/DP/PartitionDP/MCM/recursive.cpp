// TC = Exponential
// SC = O(N)

#include <bits/stdc++.h>

using namespace std;

int solve(int i, int j, vector<int> &arr){
    if(i == j) return 0;

    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k + 1, j, arr);
        if(steps < mini) mini = steps;
    }
    return mini;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(1, n - 1, arr);
    return 0;
}