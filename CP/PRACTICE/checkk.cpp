#include <iostream>
using namespace std;

string canReach(long long N, long long M, long long A, long long B) {
    long long numerator = N * B - M;
    long long denominator = B - A;

    if (denominator == 0) return "No";  // Avoid division by zero, though A < B as per constraint

    if (numerator % denominator != 0) {
        return "No";
    }

    long long x = numerator / denominator;

    if (x >= 0 && x <= N) {
        return "Yes";
    }
    return "No";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, M, A, B;
        cin >> N >> M >> A >> B;
        cout << canReach(N, M, A, B) << endl;
    }

    return 0;
}
