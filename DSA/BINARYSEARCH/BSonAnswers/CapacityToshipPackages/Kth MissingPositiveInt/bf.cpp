// TC = O(N)
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
}

//ORRR

// TC = O(maxEle)
// int findKthPositive(vector<int>& arr, int k) {
//     int n = arr.size();
//     int maxx = *max_element(arr.begin(), arr.end()) + k;
//     int cnt = 0;
//     for(int i = 1; i <= maxx; i++){
//         if(find(arr.begin(), arr.end(), i) == arr.end()){
//             cnt++;
//         }
//         if(cnt == k){
//             return i;
//         }
//     }
//     return -1;
// }

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;

    cout << findKthPositive(v, k);
}