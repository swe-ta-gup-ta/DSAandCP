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

int mex(vi v){
    int n = v.size();
    int ans = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(v[i] != i) {
            ans = i;
        }
    }
    ans = v[n - 1] + 1;
    return ans;
}

int countAndMerge(vector<int>& arr, int l, int m, int r) {
  
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
    int res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a 
        // smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i 
      	// elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions in the left and 
        // right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in 
      	// the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int inversionCount(vector<int> &arr) {
  	int n = arr.size();
  	return countInv(arr, 0, n-1);
}

int solve(){
    int m;
    cin >> m;
    vi v(m), a(1, 0);
    f(i, 0, m) cin >> v[i];
    for(auto i : v){
        if(i == 1){
            v.push_back(mex(v));
        }
        if(i == 2) {
            v.insert(v.end(), v.begin(), v.end());
        }
        int inv = 0;
        inv = inversionCount(a);
        cout << inv <<" ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
	return 0;
}