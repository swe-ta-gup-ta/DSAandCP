// Time Complexity: O(N*M)
// Reason: There are two nested loops.

// Space Complexity: O(M)
// Reason: We are using an external array of size ‘M+1’ to store only two rows.

#include <iostream>
#include <vector>

using namespace std;

int LCS(string text1, string text2) {
    
    int n = text1.size(), m = text2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int i = 0; i <= n; i++) prev[0] = 0;

    for(int i  = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i - 1] == text2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }
            else{
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

int main(){
    string s1, s2;
    cout << LCS(s1, s2);
    return 0;
}