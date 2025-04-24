#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    string s;
		cin >> s;
		string t = s;
        int n = s.size();
        string ans = "";
        while(true){
            if(t.size() == 2) break;
            for(int i = 0; i < t.size() - 1; i++){
                int x = t[i] - '0';
                int y = t[i+1] -'0';
                char a = ((x + y) % 10) + '0';
                ans += a;
            }
            t = ans;
            cout<<ans.size()<<"*"<<t.size()<<endl;
            ans = "";
        }
        if(t[0] == t[1]) cout<<true<<endl;
        else cout<< false<<endl;
	}

}
