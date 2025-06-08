#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, int X) {
    vector<int> P(N + 1, -1);  // 1-based indexing
    vector<bool> used(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        int v = X | i;
        if (v <= N && (v | i) == X && !used[v]) {
            P[i] = v;
            used[v] = true;
        }
    }

    // Fill remaining positions with unused values
    int idx = 1;
    for (int i = 1; i <= N; ++i) {
        if (P[i] == -1) {
            while (used[idx]) idx++;
            P[i] = idx;
            used[idx] = true;
        }
    }

    return vector<int>(P.begin() + 1, P.end()); // drop index 0
}


int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n, x;
	    cin >> n >> x;
	    vector<int> v = solve(n, x);
		for(auto i : v) cout << i  << " ";
		cout << "\n";
	}
}