#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0, cnt = 0;
        int last = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] != '0'){
                last = i;
                break;
            }
        }
        for(int i = 0; i < last; i++){
            if(s[i] != '0') cnt++; 
        }
        ans = cnt + (n - last - 1);
        cout << ans << endl;
    }
}