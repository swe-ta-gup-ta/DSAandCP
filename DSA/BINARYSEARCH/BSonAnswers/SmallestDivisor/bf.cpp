// TC = O((maxEle(arr)) * (n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;


int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size(); //size of array.
    //Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());

    //Find the smallest divisor:
    for (int d = 1; d <= maxi; d++) {
        //Find the summation result:
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        if (sum <= limit)
            return d;
    }
    return -1;
}


int main(){
    int n;
    cin >> n;
    vector<int> bloomDay(n);
    for(int i = 0; i < n; i++) cin >> bloomDay[i];
    int m, k;
    cin >> m >> k;

    cout << smallestDivisor(bloomDay, k, m);
}