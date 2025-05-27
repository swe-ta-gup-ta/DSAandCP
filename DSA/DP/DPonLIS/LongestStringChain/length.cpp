// TC = O(N * N) * length of string
// SC = O (N)

// https://leetcode.com/problems/longest-string-chain/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string &s1, string &s2){
    if(s1.size() != s2.size() + 1) return false;
    int first = 0, second = 0;
    while(first < s1.size()){
        if(s1[first] == s2[second]){
            first++, second++;
        }
        else first++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    return false;
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](string s1, string s2){
        return s1.size() < s2.size();
    });
    int n = words.size();
    vector<int> dp(n, 1);
    int maxx = 1;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(check(words[i], words[prev]) && 1 + dp[prev] > dp[i]){
                dp[i] = dp[prev] + 1;
            }
        }
        if(dp[i] > maxx) maxx = dp[i];
    }
    return maxx;
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout<< longestStrChain(v);
}