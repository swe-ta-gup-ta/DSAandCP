#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> a(n);
	    for(int i = 0; i < n; i++) cin >> a[i];
	    int ans = 0;
	    for(int i = 0; i <  n - 1; i++){
	        if(a[i] > a[i + 1]){
	            ans = max(ans, 32 - __builtin_clz(a[i] ^ a[i + 1]));
	            a[i + 1] = a[i];
	        }
	    }
	    cout << ((ans) ? (1 << (ans - 1)) : ans) << endl;
	}

}
