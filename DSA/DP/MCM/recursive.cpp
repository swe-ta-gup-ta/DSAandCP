#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int j, vector<int> &arr){
    if(i == j) return 0;
    int minn = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k + 1, j, arr);
        minn = min(minn, steps);
    }
    return minn;
}

int matrixChainMultiplication(vector<int> &arr, int n){
    return solve(1, n - 1, arr);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << matrixChainMultiplication(arr, n);
    return 0;
}