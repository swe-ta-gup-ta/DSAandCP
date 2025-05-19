///space optimised TC= O(N * M) SC = O( N)

#include <iostream>
#include <vector>

using namespace std;

int minDistance(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<double>prev(m + 1, 0), curr(m + 1, 0);
    curr[0] = 0;
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++){
        curr[0] = i;
        for(int j = 1; j <= m; j++){

            if(s[i - 1] == t[j - 1]) {
                curr[j] = prev[j - 1]; 
            }
            else{ 
                int insert = 1 + curr[j -1];
                int delte = 1 + prev[j]; 
                int replace = 1 + prev[j - 1]; 
                curr[j] = min(insert, min(delte, replace));
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << minDistance(str1, str2);
    return 0;
}