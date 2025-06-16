// TC = O(n * log(m))
// SC = O(1)

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &mat, int n, int m){
    int cnt1 = 0, idx = -1, ans =0;
    for(int i = 0; i < n; i++){
        int cnt1 = m - (lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin());
        if(cnt1 > ans) {
            ans = cnt1;
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    cout << solve(mat, n, m);
    return 0;
}