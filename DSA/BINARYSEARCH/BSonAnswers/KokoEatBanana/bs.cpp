// TC = O(log(maxEle(arr)) * (n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

long long calculateTotalHours(vector<int> &v, int hourly) {
    long long totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int>& piles, int h) { 
    int maxi = *max_element(piles.begin(), piles.end());
    int low = 1, high = maxi, ans = INT_MAX;

    while(low <= high){
        int mid = (low + high) / 2;
        long long totHrs = calculateTotalHours(piles, mid);
        if(totHrs <= h) {
            ans = mid;
            high = mid -1;
        }
        else low = mid + 1;
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

    cout << minimumRateToEatBananas(piles, h);
}