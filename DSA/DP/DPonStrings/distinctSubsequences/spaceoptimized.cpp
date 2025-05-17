///space optimised TC= O(N * M) SC = O( N)

#include <iostream>
#include <vector>

using namespace std;

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<double>prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = curr[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(s[i - 1] == t[j - 1]) curr[j] = prev[j - 1] + prev[j];
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return (int)prev[m];
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << numDistinct(str1, str2);
    return 0;
}