// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>

using namespace std;

int solveFloor(vector<int> &arr, int n, int target){
    int low = 0, high = n - 1, ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int solveCeil(vector<int> &arr, int n, int target){
    int low = 0, high = n - 1, ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= target) {
            ans = arr[mid];
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
    cout << solveFloor(v, n, target);
    cout << solveCeil(v, n, target);
}