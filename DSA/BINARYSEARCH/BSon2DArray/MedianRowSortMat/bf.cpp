// TC = O(n * m) + O(n * m) * O (log(n * m))
// SC = O(1)
// Given = (n * m) id odd

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<vector<int>> mat, int n, int m){
    vector<int> ele;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            ele.push_back(mat[i][j]);
        }
    }
    sort(ele.begin(), ele.end());
    return (n * m) / 2;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    cout << solve(mat, n, m);
    return 0;
}