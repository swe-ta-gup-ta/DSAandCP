// TC = O((n))
// SC = O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int koko(vector<int> &piles, int h) {
    int totHrs = 0;
    int n = piles.size();
    for(int i = 0; i  < n; i++){
        totHrs += ceil(piles[i] / h);
    }
    return totHrs;
}

int main(){
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; i++) cin >> piles[i];
    int h;
    cin >> h;

    cout << koko(piles, h);
}