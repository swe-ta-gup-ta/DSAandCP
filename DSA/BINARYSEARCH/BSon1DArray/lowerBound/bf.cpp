// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= target) {
            return i;
        }
    }
    return n;
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