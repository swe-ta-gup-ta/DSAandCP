#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        if(k % 2 == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}