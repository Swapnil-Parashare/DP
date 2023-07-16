#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :

    vector<vector<int>> dp;

    int solve(vector<int>& coins, int n, int sum)
    {
        // Initialization
        for(int j = 0 ; j <= sum ; j++) dp[0][j] = 0;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;

        // Choice Diagram
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= sum ; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] =  dp[i][j-coins[i-1]]              // Include (Not Processed)
                                    +
                                dp[i-1][j];                      // Not Include (Processed)
                }
                else
                {
                    dp[i][j] = dp[i-1][j];                       // Not Include (Processed)
                }
            }
        }
        return dp[n][sum];
    }

    int coinChange(vector<int>& coins, int n, int sum)
    {
        dp.resize(n+1,vector<int>(sum+1));
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