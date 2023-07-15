#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:

    vector<vector<int>> dp;

    int solve(vector<int> weights, vector<int> values, int n, int W) 
    { 
        
       // Base Condition
       if( W == 0 || n == 0 )
       {
           return 0;
       }

       // Memoization
       if(dp[n][W] != -1) return dp[n][W];
       
       // Choice Diagram
       if(weights[n-1] <= W)
       {
           return dp[n][W] = 
           max(
           values[n-1] + solve(weights, values, n, W-weights[n-1])          // Include        (Not moving to previous item. i.e NOT PROCESSED)
                                    ,
                         solve(weights,values,n-1,W)                        // Don't Include
            );
       }
       else
       {
           return dp[n][W] = solve(weights,values,n-1,W);                               // Don't Include
       }
    }

    int knapSack(vector<int> weights, vector<int> values, int n, int W) 
    {
        dp.resize(n+1,vector<int>(W+1,-1));
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