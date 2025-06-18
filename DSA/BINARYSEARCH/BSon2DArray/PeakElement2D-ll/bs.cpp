// TC = O(n * log(m))
// SC = O(1)

#include <iostream>
#include <vector>

using namespace std;

int maxEle(vector<vector<int>>& mat, int n, int m, int mid ){
    int mx = 0, ans =  0;
    for(int i = 0; i < n; i++){
        if(mat[i][mid] > mx){
            mx = mat[i][mid];
            ans = i;
        }
    }
    return ans;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        int row = maxEle(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if(mat[row][mid] > left && mat[row][mid] > right){
            return {row, mid};
        }
        else if(mat[row][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
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
    vector<int> ans = findPeakGrid(mat);
    for(auto i : ans) cout << i << " ";
    return 0;
}