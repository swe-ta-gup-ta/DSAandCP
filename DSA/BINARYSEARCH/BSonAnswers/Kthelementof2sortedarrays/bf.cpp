// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.

// Space Complexity: O(m+n), where m and n are the sizes of the given arrays.

// Reason: We are using an extra array of size (m+n) to solve this problem.


#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    vector<int> arr3;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < m) arr3.push_back(a[i++]);
    while (j < n) arr3.push_back(b[j++]);
    return arr3[k - 1];
}


int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);
    for(int i = 0;i < n1; i++) cin >> nums1[i];
    for(int i = 0;i < n2; i++) cin >> nums2[i];
    int k;
    cin >> k;
    cout <<kthElement(nums1, nums2, n1, n2, k);
}

