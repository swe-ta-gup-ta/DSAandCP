// TC = O(N * N)
// SC = O(N)
// https://leetcode.com/problems/palindrome-partitioning-ii/description/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int isPalin(string s){
    int n = s.size();
    int i = 0, j = n - 1, f = 0;
    while(i <= j) {
        if(s[i] != s[j]) {
            f = 1;
            break;
        }
        i++, j--;
    }
    if(f == 1) return false;
    return true;
}


int minCut(string s){
    int n = s.size();
    if(n == 1) return 0;
    vector<int> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; i--){
        int ans = INT_MAX;
        string temp = "";
        for(int j = i; j < n; j++){            
            temp += s[j];
            if(isPalin(temp)){
                int cut = 1 + dp[j + 1];
                ans = min(ans, cut);
            }
        }
        dp[i] = ans;
    }

    return dp[0] - 1;
}

int main() {
    string s;
    cin >> s;
    cout << minCut(s);
    return 0;
}