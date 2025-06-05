// TC = O(maxEle(arr) * (n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {

    int maxi = *max_element(v.begin(), v.end());
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; i++) cin >> piles[i];
    int h;
    cin >> h;

    cout << minimumRateToEatBananas(piles, h);
}