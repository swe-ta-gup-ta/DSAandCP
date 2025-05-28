#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int ans = n; // case where we just kill all monsters individually
    for (int i = 0; i < n; ++i) {
        int x = A[i];
        int kills = n - i;
        ans = min(ans, x + kills - 1);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        cout << solve(A) << endl;
    }
    return 0;
}
