// TC = O(2^n * 2^m) => where 2^n is the total number of subsequences of string of length 'n'
// Space Complexity: O(N*M) + O(N+M)

#include <iostream>

using namespace std;

int solve(int i, int j, string s1, string s2){

    if(i < 0 || j < 0) return 0;

    if(s1[i] == s2[j]){
        return 1 + solve(i - 1, j - 1, s1, s2);
    }
    else{
        return max(0 + solve(i -1, j, s1, s2), 0 + solve(i, j - 1, s1, s2));
    }
}

int LCS(string text1, string text2){
    int n = text1.size(), m = text2.size();
    return solve(n - 1, m - 1, text1, text2);
}

int main(){
    string s1, s2;
    cout << LCS(s1, s2);
    return 0;
}