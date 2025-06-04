// TC = O(log(num) * n)
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nthRoot(int n, int num) {
    int ans = -1;
    int low = 1, high = num;
    while(low <= high){
        int mid = (low + high) / 2;
        int x = 1;
        for(int i = 0; i < n; i++) x *= mid;
        if(x == num) return mid;
        else if(x < num) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << nthRoot(n, m);
}