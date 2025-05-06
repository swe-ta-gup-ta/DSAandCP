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

const unsigned int M = 1000000007;

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



int solve(){
    int n;
    cin >> n;
    vi v(n), cnt(n, 0);
    f(i, 0, n) cin >> v[i], cnt[v[i]]++;
    int ans = 1;
    int mod = 998244353;
    f(i, 0, n/2){
        if(cnt[i] + cnt[n - i - 1] != 2) return 0;
        ans = ans * 2 % mod;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
	return 0;
}