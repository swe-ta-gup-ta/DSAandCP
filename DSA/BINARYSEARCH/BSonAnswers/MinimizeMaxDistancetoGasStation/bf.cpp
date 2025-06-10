// Time Complexity: O(k*n) + O(n), n = size of the given array, k = no. of gas stations 
// to be placed.
// Reason: O(k*n) to insert k gas stations between the existing stations with maximum 
// distance. Another O(n) for finding the answer i.e. the maximum distance.

// Space Complexity: O(n-1) as we are using an array to keep track of placed gas stations.

// https://takeuforward.org/arrays/minimise-maximum-distance-between-gas-stations/

#include <iostream>
#include <vector>

using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength =
                diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength =
            diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin >> arr[i];
    int k;
    cin >> k;
    cout << minimiseMaxDistance(arr, k);
    return 0;
}