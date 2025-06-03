// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> &arr, int n, int target){
    return lower_bound(arr.begin(), arr.end(), target) - arr.begin();
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