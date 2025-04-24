#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin >> t;
	while(t--){
		vector<ll> v(3);
		for(ll i = 0; i < 3; i++) cin >> v[i];
		ll ans = 0;
		ll cnt0 = 0;
		sort(v.begin(), v.end());
		for(ll i = 0; i < 3; i++){
			if(v[i] == 0) cnt0++;
		}
		if(cnt0 == 3) ans = 0;
		else if(cnt0 == 2) ans = 0;
		else if(cnt0 == 1) ans = v[1];
		else {
			ans = v[0] + v[1];
			if(v[0] % 2 == 1 && v[1] % 2 == 1) ans--;
		}
		cout << ans << endl;

	}
}
