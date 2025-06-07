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





void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 1; i <= n; i++) v[i -1] = i;
    for(int i = 1; i <= n; i++){
        if(v[i - 1] != i) continue;
        if((i | x) != x) continue;
        int j = i ^ x;
        if(j < 1 || j > n) continue;
        swap(v[i - 1], v[j -1]);
    }
    
    for(auto i : v){
        cout << i <<" ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}