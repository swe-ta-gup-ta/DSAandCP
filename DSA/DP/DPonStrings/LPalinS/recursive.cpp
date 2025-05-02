// TC = O(2^n * 2^m) => where 2^n is the total number of subsequences of string of length 'n'
// Space Complexity: O(N*M) + O(N+M)


///Same as that of LCS just string1 => original string and String2 => REveresed string
// do all approaches same 

#include <iostream>
#include <algorithm>

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

int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return LCS(s, t);
}

int main(){
    string s1, s2;
    cout << LCS(s1, s2);
    return 0;
}