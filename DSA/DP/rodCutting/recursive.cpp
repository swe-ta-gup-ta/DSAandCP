// if N = 5 => rod lengths can be 1, 2, 3, 4, 5
// Collect rod lengths to make N => maximize the price

// Try to pick lengths and sum them up to make N
//Steps to write recurrence
// 1. Express in terms of index (idx, Target)
// 2. Explore all possibilities => nottake, take
// 3. Maximise the prize max(notTake, take)


//TC = O(exponenetial)
// SC = O(target)

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(int idx, int N, vector<int>& costs){
    if(idx == 0){
        return N * costs[0];

    }

    int notTake = 0 + solve(idx - 1, N, costs);
    int take = INT_MIN;
    int rodLength = idx + 1;
    if(rodLength <= N) take = costs[idx] + solve(idx, N - rodLength, costs);

    return max(take, notTake);
}

int rodCutting(int n, int capacity, vector<int>& costs) {
    return solve(n - 1, n, costs);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> wt(n), costs(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> costs[i];
    cout << rodCutting(n, capacity, costs);
    return 0;
}