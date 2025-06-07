// TC = O(maxEle(arr) - minEle(arr) * (n))
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
    int minn = v[0];
    int maxx = v[n - 1];
    for(int i = 1; i <= (maxx - minn); i++){
        if(canWePlace(v, i, cows)){
            continue;
        }
        else return (i - 1);
    }
    return -1;
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