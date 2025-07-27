#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumSubsequences(std::string s) {
        // The target subsequence characters.
        char p0 = 'L', p1 = 'C', p2 = 'T';
        int n = s.length();

        // --- Step 1: Precompute prefix counts of 'L' and suffix counts of 'T' ---
        // countL[i] will store the number of 'L's in the prefix s[0...i-1].
        std::vector<long long> countL(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            countL[i + 1] = countL[i] + (s[i] == p0);
        }

        // countT[i] will store the number of 'T's in the suffix s[i...n-1].
        std::vector<long long> countT(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            countT[i] = countT[i + 1] + (s[i] == p2);
        }

        // --- Step 2: Calculate the base count and potential gains ---
        long long base_count = 0; // Subsequences in the original string
        long long gain_by_L = 0;  // Gain if we insert 'L' at the beginning
        long long gain_by_T = 0;  // Gain if we insert 'T' at the end

        // Iterate through the string to find all 'C's.
        // For each 'C', calculate its contribution to the counts.
        for (int i = 0; i < n; ++i) {
            if (s[i] == p1) {
                // 'L's before this 'C' and 'T's after this 'C' form subsequences.
                // countL[i] gives 'L's in s[0...i-1].
                // countT[i+1] gives 'T's in s[i+1...n-1].
                base_count += countL[i] * countT[i + 1];

                // If we add an 'L' at the start, it forms a subsequence with this 'C'
                // and all 'T's that come after this 'C'.
                gain_by_L += countT[i + 1];

                // If we add a 'T' at the end, it forms a subsequence with this 'C'
                // and all 'L's that came before this 'C'.
                gain_by_T += countL[i];
            }
        }

        // --- Step 3: Calculate the maximum gain by inserting 'C' ---
        long long gain_by_C = 0;
        // We can insert 'C' at any position from 0 to n.
        for (int i = 0; i <= n; ++i) {
            // If we insert 'C' at index i, it forms subsequences with
            // 'L's before it (countL[i]) and 'T's after it (countT[i]).
            gain_by_C = std::max(gain_by_C, countL[i] * countT[i]);
        }

        // --- Step 4: Determine the final answer ---
        // The result is the base count plus the maximum possible gain from any single insertion.
        // The gain can be 0 if we choose not to insert any character.
        long long max_gain = std::max({0LL, gain_by_L, gain_by_T, gain_by_C});

        return base_count + max_gain;
    }
};

// Example usage
int main() {
    Solution sol;
    std::string s1 = "LMCT";
    std::cout << "Input: " << s1 << ", Output: " << sol.maximumSubsequences(s1) << std::endl; // Expected: 2

    std::string s2 = "LCCT";
    std::cout << "Input: " << s2 << ", Output: " << sol.maximumSubsequences(s2) << std::endl; // Expected: 4

    std::string s3 = "L";
    std::cout << "Input: " << s3 << ", Output: " << sol.maximumSubsequences(s3) << std::endl; // Expected: 0
    
    std::string s4 = "TCL";
    std::cout << "Input: " << s4 << ", Output: " << sol.maximumSubsequences(s4) << std::endl; // Expected: 0

    std::string s5 = "LCT";
    std::cout << "Input: " << s5 << ", Output: " << sol.maximumSubsequences(s5) << std::endl; // Expected: 2

    return 0;
}


"L"
"TCL"
"LCT"
"LT"©leetcode