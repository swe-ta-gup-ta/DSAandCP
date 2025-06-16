#include <bits/stdc++.h>
#define intt long long
using namespace std;

int main() {
	// your code goes here
	intt t;
	cin >> t;
	while(t--){
	    intt n, q;
	    cin >> n >> q;
	    vector<intt> a(n);
	    for(intt i = 0; i < n; i++) cin >> a[i];
	    
	    intt ans = 0;
        for(intt i = 0; i < n - 1; i++){
            ans += min(a[i] , a[i + 1]);
        }
	    while(q--){
	        intt i , x;
	        cin >> i >> x;
            
            intt al = 0, ar = 0, cal = 0, car = 0;
	        if(i == 1){
	            i--;
                ar = min(a[i], a[i + 1]);
                car = min(x, a[i + 1]);
                ans += car;
                ans -= ar;
            }

            else if(i == n){
                i--;
                al = min(a[i], a[i - 1]);
                cal = min(x, a[i - 1]);
                ans += cal;
                ans -= al;
                // cout << cal << " "<< al;
            }
            else{
                i--;
                ar = min(a[i], a[i + 1]);
                car = min(x, a[i + 1]);
                al = min(a[i], a[i - 1]);
                cal = min(x, a[i - 1]);
                ans += (cal + car);
                ans -= (al + ar);
            }
            a[i] = x;
            // for(auto i : a) cout<<i << " "; 
            // cout << endl;
            cout << ans << endl;
	    }
	}

}
