// steps
// 1. write the base case
// 2. what are the changing parameters (index, target)
// 3. copy the recurrence

#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int> &coins, int n)
{

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i <= amount; i++)
    {
        dp[0][i] = (i % coins[0]) == 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (coins[i] <= j)
                take = dp[i][j - coins[i]];

            dp[i][j] = take + notTake;
        }
    }

    return dp[n - 1][amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << change(amount, arr, n);
    return 0;
}

// TC = O(n * target)
// SC = O(n * target)