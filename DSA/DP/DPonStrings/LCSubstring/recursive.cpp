// Time Complexity: O(m x n x min(m, n))
// Auxiliary Space: O(min(m, n))

#include <iostream>
#include <vector>

using namespace std;

int LCsuffix(string &s1, string &s2, int n, int m){
    if (n == 0 || m == 0 || s1[n - 1] != s2[m - 1])
        return 0;
    return 1 + LCsuffix(s1, s2, n - 1, m - 1);
}

int LCSubstring(string text1, string text2){
    int n = text1.size(), m = text2.size();
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int curr = 0;
            
            ans = max(ans, LCsuffix(text1, text2, i, j));
        }
    }
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCSubstring(s1, s2);
    return 0;
}
