#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin >> t;
	while(t--){
	    ll n, k;
	    cin >> n >> k;
	    vector<ll> v(n);
	    for(ll i = 0; i < n; i++) cin >> v[i];
	    ll i = 0;
	    sort(v.begin(), v.end());
	    ll summ = accumulate(v.begin(), v.end(), 0);
	    ll sum = 0;
	    sum += summ;
	    ll minn = v[0];
	    ll minn2 = v[1];
	    while(k--){
	        ll insertEle = (minn + minn2 + 1) / 2;
	        sum += insertEle;
	        if(insertEle == minn2) {
	            break;
	        }
	        minn2 = insertEle;
	    }
	    if(k > 0) sum += k * minn2;
	    cout << sum << endl;
	}

}
