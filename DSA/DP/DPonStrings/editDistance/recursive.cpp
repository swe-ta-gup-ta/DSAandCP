///recursive TC= exponential - very big 
//problem link = https://leetcode.com/problems/edit-distance/description/

#include <iostream>
#include <vector>

using namespace std;

int solve(string &s, string &t, int i, int j){
    
    if(j < 0) return i + 1; 
    if(i < 0) return j + 1;

    if(s[i] == t[j]) {
        return solve(s, t, i - 1, j - 1);
    }
    int insert = 1 + solve(s, t, i, j - 1);
    int delte = 1 + solve(s, t, i - 1, j);
    int replace = 1 + solve(s, t, i - 1, j - 1);
    return min(insert, min(delte, replace));
}

int minDistance(string &s, string &t) {
    int n = s.size(), m = t.size();

    return solve(s, t, n - 1, m - 1);
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << minDistance(str1, str2);
    return 0;
}