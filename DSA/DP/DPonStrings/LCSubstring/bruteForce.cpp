// Time Complexity: O(m x n x min(m, n))
// Auxiliary Space: O(1)

#include <iostream>
#include <vector>

using namespace std;

int LCSubstring(string text1, string text2){
    int n = text1.size(), m = text2.size();
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int curr = 0;
            while((i + curr) < n && (j + curr) < m && text1[i + curr] == text2[j + curr]) 
                curr++;
            ans = max(ans, curr);
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
