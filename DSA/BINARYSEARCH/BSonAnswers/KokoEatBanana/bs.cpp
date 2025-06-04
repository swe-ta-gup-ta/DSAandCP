// TC = O(log(n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int koko(vector<int> &piles, int h) {
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
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; i++) cin >> piles[i];
    int h;
    cin >> h;

    cout << koko(piles, h);
}