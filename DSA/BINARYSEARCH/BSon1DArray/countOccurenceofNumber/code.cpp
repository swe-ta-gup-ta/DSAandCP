// TC = 2 * O(log(n))
// SC = O(1)


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> firstAndLastOccurence(vector<int> &arr, int n, int target){
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    if(lb == n || arr[lb] != target) return {-1, -1};
    return {lb, ub - 1};
}

int countOccurrences(vector<int> &arr, int target){
    int n = arr.size();
    vector<int> x = firstAndLastOccurence(arr, n, target);
    if(x[0] == -1) return 0;
    // for(auto i : x) cout << i << " ";
    int first = x[0], last = x[1];
    return (last - first) + 1; 
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int target;
    cin >> target;

    cout << countOccurrences(v, target);
    
}