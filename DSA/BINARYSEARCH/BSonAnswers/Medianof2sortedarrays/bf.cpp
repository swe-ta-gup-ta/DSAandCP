// Time Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.

// Space Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
// Reason: We are using an extra array of size (n1+n2) to solve this problem.

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/


#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);
    for(int i = 0;i < n1; i++) cin >> nums1[i];
    for(int i = 0;i < n2; i++) cin >> nums2[i];
    cout <<median(nums1, nums2);
}

