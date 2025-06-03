// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>

using namespace std;

int upperBound(vector<int> &arr, int target, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > target) {
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
    cout << upperBound(v, n, target);
}