#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int x = n / k;
	    vector<int> ans(n, 0);
	    for(int i = 1; i <= n; i++) ans[i - 1] = i;
	   // for(auto i : ans) cout << i << " ";
	    // int i = 0, j = x;
	    // while(j < n){
	    //     reverse(ans.begin() + i, ans.end() - (n - j));
	    //     i = j;
	    //     j += x;
	    // }
	    // for(auto i : ans) cout << i << " ";
	    // cout << endl;
        reverse(ans.begin(), ans.end() - 5);
        for(auto i : ans) cout <<  i << " "; 
	}

}
