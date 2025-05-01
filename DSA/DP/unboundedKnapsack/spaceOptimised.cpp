// Time Complexity: O(N*W)
// Reason: There are two nested loops.

// Space Complexity: O(W)
// Reason: We are using an external array of size ‘W+1’ to store only one row.

///using two - 1-D array

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int unboundedKnapsack(int n, int capacity, vector<int>& wt, vector<int>& val) {

    vector<int> prev(capacity + 1, 0), curr(capacity + 1, 0);

    for(int i = 0; i <= capacity; i++) prev[i] = ((int)(i/wt[0])) * val[0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= capacity; j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if(wt[i] <= j) take = val[i] + curr[j - wt[i]];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[capacity];
}

int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> val[i];
    cout << unboundedKnapsack(n, capacity, wt, val);
    return 0;
}

// ///using one - 1-D array => more optimized

// #include <iostream>
// #include <vector>
// #include <limits.h>

// using namespace std;

// int unboundedKnapsack(int n, int capacity, vector<int>& wt, vector<int>& val) {

//     vector<int> prev(capacity + 1, 0);

//     for(int i = 0; i <= capacity; i++) prev[i] = ((int)(i/wt[0])) * val[0];

//     for(int i = 1; i < n; i++){
//         for(int j = 0; j <= capacity; j++){
//             int notTake = 0 + prev[j];
//             int take = INT_MIN;
//             if(wt[i] <= j) take = val[i] + prev[j - wt[i]];

//             prev[j] = max(take, notTake);
//         }
//     }
//     return prev[capacity];
// }

// int main(){
//     int n, capacity;
//     cin >> n >> capacity;
//     vector<int> wt(n), val(n);
//     for(int i = 0; i < n; i++) cin >> wt[i];
//     for(int i = 0; i < n; i++) cin >> val[i];
//     cout << unboundedKnapsack(n, capacity, wt, val);
//     return 0;
// }