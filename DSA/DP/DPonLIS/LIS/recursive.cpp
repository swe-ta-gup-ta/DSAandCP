// ***BRUTE FORCE => Genrate all the subsequences (by using POWERSET or RECURSION) then check for LIS (Store the longesst)

// TC = 2 ^ N
// SC = O (N)

#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int prev, vector<int> &v) {

    if(idx == v.size()) return 0;

    int len = 0 + solve(idx + 1, prev, v);
    if(prev == -1 || v[idx] > v[prev]){
        len = max(len, 1 + solve(idx + 1, idx, v));
    }
    return len ;
}

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    return solve(0, -1, nums);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << lengthOfLIS(v) << endl;
}