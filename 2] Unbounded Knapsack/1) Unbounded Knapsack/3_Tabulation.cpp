#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:

    vector<vector<int>> dp;

    int solve(vector<int> weights, vector<int> values, int n, int W) 
    { 
        
       // Initializaton
       for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
       for(int j = 0 ; j <= W ; j++) dp[0][j] = 0;
       
       // Choice Diagram

       for(int i = 1; i <= n ; i++)
       {
           for(int j = 1 ; j <= W ; j++)
           {
                if(weights[i-1] <= j)
                {
                    dp[i][j] =  max(
                    values[i-1] + dp[i][j-weights[i-1]]         // Include        (Not moving to previous item. i.e NOT PROCESSED)
                                             ,
                                  dp[i-1][j]                    // Don't Include
                     );
                }
                else
                {
                    dp[i][j] = dp[i-1][j];                // Don't Include
                }
            }
       }
        return dp[n][W];
    }

    int knapSack(vector<int> weights, vector<int> values, int n, int W) 
    {
        dp.resize(n+1,vector<int>(W+1));
        return solve(weights,values,n,W);
    }

};

int main()
{
    vector<int> weights = {1,1,1};
    vector<int> values = {10,20,30};
    int n = 3;
    int capacity = 2;

    Solution S1;

    int ans = S1.knapSack(weights,values,n,capacity);

    cout << ans << endl;
}