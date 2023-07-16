#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :



    int solve(vector<int>& coins, int n, int sum)                // Minimum Coins Possible
    {
        // Base Condition
        if(sum == 0) return 0;
        if(n == 0) return INT_MAX - 1;                           // This is the case when 'sum' is not achievable.

        // Choice Diagram
        if(coins[n-1] <= sum)
        {
            return min(
                         1 + solve(coins,n,sum-coins[n-1])       // Include
                                      ,
                         solve(coins,n-1,sum)                    // Not Include
            );
        }
        else
        {
            return solve(coins,n-1,sum);                          // Not Include
        }
    }

    int coinChange(vector<int>& coins, int n, int sum)                // Minimum Coins Possible
    {
        int ans = solve(coins,n,sum);
        return (ans == INT_MAX - 1 ? -1 : ans);
    }

};

int main()
{
    vector<int> coins = {25,10,5};
    int sum = 30;

    Solution S1;

    cout << S1.coinChange(coins,coins.size(),sum) << endl;
}