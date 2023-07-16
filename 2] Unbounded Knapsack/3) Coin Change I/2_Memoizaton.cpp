#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :

    vector<vector<int>> dp;

    int solve(vector<int>& coins, int n, int sum)
    {
        // Base Condition
        if(sum == 0) return 1;
        if(n == 0) return 0;

        // Memoization
        if(dp[n][sum] != -1) return dp[n][sum];

        // Choice Diagram
        if(coins[n-1] <= sum)
        {
            return dp[n][sum] = solve(coins,n,sum-coins[n-1])                              // Include (Not Processed)
                                        +
                                solve(coins,n-1,sum);                                      // Not Include (Processed) 
        }
        else
        {
            return dp[n][sum] = solve(coins,n-1,sum);                                       // Not Include (Processed)
        }
    }

    int coinChange(vector<int>& coins, int n, int sum)
    {
        dp.resize(n+1,vector<int>(sum+1, -1));
        return solve(coins,n,sum);
    }

};

int main()
{
    vector<int> coins = {1,2,3};
    int sum = 5;

    Solution S1;

    cout << S1.coinChange(coins,coins.size(),sum) << endl;
}

/* Same as "Count Subset Sum" Problem. Only difference is infinite supply of elements. i.e (Unbounded Knapsack)*/
