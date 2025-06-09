// Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, 
// sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Reason: We are applying binary search on [max(arr[]), sum(arr[])]. 
// Inside the loop, we are calling the countStudents() function for the value of ‘mid’. 
// Now, inside the countStudents() function, we are using a loop that runs for N times.

// Space Complexity:  O(1) as we are not using any extra space to solve this problem.


//THE PROBLEM 1.Book Allocation Problem
            //   2.Split array - Largest Sum
            //   3.Painter's partition THESE THREEE PROBLEMS ARE EXACT SAME
            
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int stud) {
    //book allocation isimpossible:
    int n = arr.size();
    if (stud > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > stud) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int stud;
    cin >> stud;

    cout << findPages(arr, stud);
}