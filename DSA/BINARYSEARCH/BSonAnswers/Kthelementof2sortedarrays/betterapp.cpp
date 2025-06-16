// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.

// Space Complexity: O(1), as we are not using any extra space to solve this problem.


#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    int ele = -1;
    int cnt = 0; //counter
    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (cnt == k - 1) ele = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == k - 1) ele = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < m) {
        if (cnt == k - 1) ele = a[i];
        cnt++;
        i++;
    }
    while (j < n) {
        if (cnt == k - 1) ele = b[j];
        cnt++;
        j++;
    }
    return ele;
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

