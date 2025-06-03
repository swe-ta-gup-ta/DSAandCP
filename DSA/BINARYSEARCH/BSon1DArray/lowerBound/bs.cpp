// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> &arr, int n, int target){
    int low = 0, high = n - 1, ans = n;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
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
    cout << lowerBound(v, n, target);
}