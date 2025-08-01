#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> findnge(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i = n -1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        nge[i] = (st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return nge;
}
vector<int> findnse(vector<int> &arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        nse[i] = (st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return nse;
}
vector<int> findpse(vector<int> &arr) {
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i = 0; i <= n; i++){
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        pse[i] = (st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return pse;
}
vector<int> findpge(vector<int> &arr) {
    int n = arr.size();
    vector<int> pge(n);
    stack<int> st;
    for(int i = 0; i <= n; i++){
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        pge[i] = (st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return pge;
}

int main() {
    int n;
    cin >>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = findpse(v);
    for(auto i : ans) cout << i << " ";

}