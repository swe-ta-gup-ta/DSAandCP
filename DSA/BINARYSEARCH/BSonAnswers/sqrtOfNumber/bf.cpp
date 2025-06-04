// TC = O(n)
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sqrtNumber(int num) {
    int ans = 1;
    for(int i = 1; i < num; i++){
        if(i * i <= num) ans = i;
        else break;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << sqrtNumber(n);
}