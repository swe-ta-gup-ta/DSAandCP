#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin >>n;
    string s, t;
    cin >> s;
    cin >> t;
    int first = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            cout << -1 << endl;
            return;
        }
        if(s[i] == '1'){
            first = i;
            break;
        }
    }
    if(first == -1){
        cout << 0 << endl;
        return;
    }

    vector<int> res;
    for(int i = first + 1; i < n; i++){
        if(s[i] != '1') res.push_back(i - 1);
        s[i] = '1';
    }

    for(int i = n - 1; i >= first + 1; i--){
        if(s[i] != t[i]) res.push_back(i - 1);
    }

    cout << res.size() << endl;
    for(auto i : res) cout << i + 1 << " ";
    cout << endl;

}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    solve();
	}

}