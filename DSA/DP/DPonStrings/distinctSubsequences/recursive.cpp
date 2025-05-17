///recursive TC= exponential - very big 
//problem link = https://leetcode.com/problems/distinct-subsequences/description/

#include <iostream>
#include <vector>

using namespace std;

int solve(string &s, string &t, int i, int j){
    
    if(j < 0) return 1; 
    if(i < 0) return 0;

    if(s[i] == t[j]) {
        return solve(s, t, i - 1, j - 1) + solve(s, t, i - 1, j);
    }
    else return solve(s, t, i - 1, j);
}

int numDistinct(string &s, string &t) {
    int n = s.size(), m = t.size();

    return solve(s, t, n - 1, m - 1);
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << numDistinct(str1, str2);
    return 0;
}