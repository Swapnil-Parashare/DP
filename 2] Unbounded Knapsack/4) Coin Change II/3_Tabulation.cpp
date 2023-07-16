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
        for(int j = 0 ; j <= sum ; j++) dp[0][j] = INT_MAX -1;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;

        // Choice Diagram
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= sum ; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }

    int coinChange(vector<int>& coins, int n, int sum)
    {
        dp.resize(n+1,vector<int>(sum+1));
        int ans = solve(coins,n,sum);

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main()
{
    vector<int> coins = {25,10,5};
    int sum = 30;

    Solution S1;

    cout << S1.coinChange(coins,coins.size(),sum) << endl;
}