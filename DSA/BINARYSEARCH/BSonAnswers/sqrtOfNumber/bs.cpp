// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sqrtNumber(int num) {
    int ans = 1;
    int low = 1, high = num;
    while(low <= high){
        int mid = (low + high) / 2;
        if((mid * mid) <= num){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << sqrtNumber(n);
}