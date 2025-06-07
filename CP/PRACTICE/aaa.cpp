#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    for(int i = 0; i < n; i++) cin >> v[i];
	    
	    int ans = (n * (n + 1)) / 2, cnt1 = 0, idx = 0;
	    for(int i = 0; i < n; i++){
	        if(v[i] <= i && v[i] != 1) {
	            int x = ((i + 1) - v[i]);
	            ans -= x;
	            
	        }
	        if(v[i] <= i && v[i] == 1){
	            int x = ((i - v[i]));
	            ans -= x;
	            cnt1++;
	            idx = i;
	            
	        }
	        if(cnt1 > 0 && v[i] > i){
	            ans -= idx;
	        }
	    }
        
	   // if(v[n - 1] == n - 1) ans -= 1;
	    cout << ans << endl;
	}
}