#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    vector<vector<int>> dp;

    int solve(vector<int> prices, int n, int Length)
    {
        // Initialization
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
        for(int j = 0 ; j <= Length ; j++) dp[0][j] = 0;

        // Choice Diagram
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= Length ; j++)
            {
                if(i <= j)
                {
                    dp[i][j] = max( prices[i-1] + dp[i][j-i] , dp[i-1][j] );
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][Length];

    }

    int cutRod(vector<int> prices, int n)
    {
        int Length = n;
        dp.resize(n+1,vector<int>(Length+1));
        return solve(prices,n,Length);
    }
};

int main()
{
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();                                         

    Solution S1;

    cout << S1.cutRod(prices,n) << endl;
}