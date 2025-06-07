#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> generateSubarrays(const vector<int>& arr) {
    vector<vector<int>> subarrays;
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            vector<int> subarray;
            for (int k = i; k <= j; ++k) {
                subarray.push_back(arr[k]);
            }
            subarrays.push_back(subarray);
        }
    }
    return subarrays;
}

bool isSortable(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i] <= i && i != 1) {
            for(auto i : v){
                cout << i <<" ";
            }
            cout << endl;
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int ans = 0;
        vector<vector<int>> subarrays = generateSubarrays(v);
        for(auto i : subarrays){
            vector<int> x = i;
            if(isSortable(x)){
                ans++;
            }
        } 
        cout << ans << endl;
    }
}