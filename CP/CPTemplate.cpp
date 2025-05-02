#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

ll gcd(ll a,ll b) {
    if (b==0) return a; 
    return gcd(b, a%b); 
}
ll lcm(ll a,ll b) { 
    return a/gcd(a,b)*b; 
}
bool prime(ll a) { 
    if (a==1) return 0; 
    for (int i=2;i<=round(sqrt(a));++i) 
        if (a%i==0) return 0; 
    return 1; 
}
void yes() { 
    cout<<"YES\n"; 
}
void no() { 
    cout<<"NO\n"; 
}



void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1' && (s[i] != t[i])) cnt++;
        if((s[i] != t[i])) cnt2++;
    }
    if(cnt % 2 == 1 || cnt != cnt2) no();
    else yes();
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}