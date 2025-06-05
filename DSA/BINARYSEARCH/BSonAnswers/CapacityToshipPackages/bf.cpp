// TC = O(maxEle * n)
// SC = O(1)
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    for(int mid = low; mid <= high; mid++){
        int day = 1, load = 0;
        for(int i = 0; i < n; i++){
            if(load + weights[i] > mid){
                day++;
                load = weights[i];
                
            }
            else{
                load += weights[i];
            }
        }
        if(day <= days) return mid;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int days;
    cin >> days;
    cout << shipWithinDays(v, days);
    return 0;
}

