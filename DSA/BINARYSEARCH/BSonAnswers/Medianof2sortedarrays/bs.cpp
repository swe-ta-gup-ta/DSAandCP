// Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
// Reason: We are applying binary search on the range [0, min(n1, n2)].

// Space Complexity: O(1) as no extra space is used.

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/


#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    if(n1 > n2) return median(b, a);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while(low <= high) {

        int mid1 = (low + high) / 2;
        int mid2 =  left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {
            if(n % 2 == 1) return max(l1, l2);
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else low = mid1 + 1;
    }
    return 0;
}



int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);
    for(int i = 0;i < n1; i++) cin >> nums1[i];
    for(int i = 0;i < n2; i++) cin >> nums2[i];
    cout <<median(nums1, nums2);
}

