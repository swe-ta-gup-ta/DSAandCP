#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n, m, a, b;
	    cin >> n >> m >> a >> b;
	    int ex = m - (n * a);
        int diff = b - a;
	    if (m < n * a || m > n * b) {
            cout << "No" << endl;
            continue;
	    }
	    if(ex % diff == 0){
	        cout << "Yes" << endl;
	    } 
	    else cout << "NO" << endl;
	    
	}

}
