// TC = O(log(maxEle(arr)) * (n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int minDays(vector<int>& bloomDay, int k, int m) {
    int n = bloomDay.size();
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        int cnt = 0, noOfB = 0;
        for(int i : bloomDay){
            if(i <= mid) cnt++;
            else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += cnt/k;
        if(noOfB >= m){
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
    vector<int> bloomDay(n);
    for(int i = 0; i < n; i++) cin >> bloomDay[i];
    int m, k;
    cin >> m >> k;

    cout << minDays(bloomDay, k, m);
}