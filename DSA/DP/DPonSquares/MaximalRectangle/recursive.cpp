#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int> &histo){
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for(int i = 0; i <= n; i++){
        while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
            int height = histo[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int countSquares(vector<vector<int>>& matrix) {
    
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> v[i][j];
    }

    cout << countSquares(v);
}