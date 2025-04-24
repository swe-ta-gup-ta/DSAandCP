#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(ll i = 0; i < n; i++) cin >> v[i];
        int f = 0;
        int mx = *max_element(v.begin(), v.end());
        int mn = *min_element(v.begin(), v.end());
        int cnt0 = count(v.begin(), v.end(), 0);
        if(cnt0 == n) cout << -1 << endl;
        else if(mx <= 0){
            cout << mn << " " << mn << endl;
        }
        else
        cout << mx << " " << mx << endl;
    }
}