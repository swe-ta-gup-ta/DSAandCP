// TC = O((n * lon(n))) + O(log(max - min)) * O (n)
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int canWePlace(vector<int> &v, int dist, int cows) {
    int n = v.size();
    int cntCows = 1, last = v[0];
    for(int i =1; i < n; i++){
        if(v[i] - last >= dist){
            cntCows++;
            last = v[i];
        }
        if(cntCows >= cows) return true;
    }
    
    return false; 
}

int aggressiveCows(vector<int> v, int cows) {
    int n = v.size();
    sort(v.begin(), v.end());
    int ans = 0;
    int low = v[0], high = v[n - 1];
    while(low <= high){
        int mid = (low + high) / 2;
        if(canWePlace(v, mid, cows)){
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int cows;
    cin >> cows;

    cout << aggressiveCows(arr, cows);
}