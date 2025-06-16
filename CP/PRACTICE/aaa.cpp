#include <bits/stdc++.h>
using namespace std;

int cntParry(vector<int> &a, vector<int> &b, int x, int i, int p, int d){
	if(i >= a.size()) return 0;

	if(x < a[i]) return -1e9;
	int ans = 0;

	ans = cntParry(a, b, x, i + 1, p, d);
	if(x >= b[i]){
		int temp = 1 + cntParry(a, b, x - 1, i + 1, p, d);
		if(temp != -1e9) ans = max(ans, temp);
	}
	return ans;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n, x;
	    cin >> n >> x;
	    vector<int> a(n), b(n);
	    for(int i = 0; i < n; i++) cin >> a[i];
	    for(int i = 0; i < n; i++) cin >> b[i];
		int ans = 0;
		int low = 0, high = n;
		while(low <= high){
			int mid = (low + high) / 2;
			
		}
	}

}
