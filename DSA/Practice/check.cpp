#include <bits/stdc++.h>
#define ll long long
using namespace std;

void removeMin(vector<ll> &v){
    ll n = v.size();
    ll minIdx = min_element(v.begin(), v.end()) - v.begin();
    v.erase(v.begin() + minIdx);
}

int main() {
	// your code goes here
	ll t;
	cin >> t;
	while(t--){
	    ll n;
        cin >> n;
	    vector<ll> v(2 * n);
	    for(ll i = 0; i < 2 * n; i++){
	        cin >> v[i];
	    }
	    priority_queue<int> ans;
        // for(auto i : v) cout << i << " ";
	    for(ll i = 1; i <= 2 * n; i += 2){
	        // cout << "*" << endl;
	        ans.push(v[i]);
	        ans.push(v[i - 1]);
	       // removeMin(ans);
	       ans.pop();
	    }
	    ll res = 0;
	    for(int i = 0; i < n; i++){
	        res += ans.top();
	        cout << ans.top();
            ans.pop();
	    }
	    cout << res << endl;
	}

}
