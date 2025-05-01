// Time Complexity: O(N*W)
// Reason: There are two nested loops.

// Space Complexity: O(W)
// Reason: We are using an external array of size ‘W+1’ to store only one row.

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

///using two - 1-D array
int rodCutting(int n, int capacity, vector<int>& costs) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    vector<int>prev(n + 1, 0), curr(n + 1, 0);

    for(int i = 0; i <= n; i++){
        prev[i] = i * costs[0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            int rodLength = i + 1;
            if(rodLength <= j) take = costs[i] + curr[j - rodLength];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[n];
}

// ///using one - 1-D array => more optimized
// int rodCutting(int n, int capacity, vector<int>& costs) {
//     vector<vector<int>> dp(n, vector<int>(n + 1, 0));

//     vector<int>prev(n + 1, 0);

//     for(int i = 0; i <= n; i++){
//         prev[i] = i * costs[0];
//     }

//     for(int i = 1; i < n; i++){
//         for(int j = 0; j <= n; j++){
//             int notTake = 0 + prev[j];
//             int take = INT_MIN;
//             int rodLength = i + 1;
//             if(rodLength <= j) take = costs[i] + prev[j - rodLength];

//             prev[j] = max(take, notTake);
//         }
//     }

//     return prev[n];
// }

int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> wt(n), costs(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> costs[i];
    cout << rodCutting(n, capacity, costs);
    return 0;
}