#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    
    vector<vector<int>> dp;                                         // Global DP Matrix
    
    int solve(int W, vector<int> wt, vector<int> val, int n) 
    { 
        
       // Base Condition
       if( W == 0 || n == 0 )
       {
           return 0;
       }
       
       // Choice Diagram
       
       
       if(dp[n][W] != -1) return dp[n][W];                           // Memoization
       
       if(wt[n-1] <= W)
       {
           return 
           dp[n][W] = max(
           val[n-1] + solve(W-wt[n-1], wt, val, n-1)                 // Include
                                    ,
                             solve(W, wt,val,n-1)                    // Don't Include
            );
       }
       else
       {
           return dp[n][W] = solve(W,wt,val,n-1);                               // Don't Include
       }
    }
    
    
    int knapSack(int W, vector<int> wt, vector<int> val, int n) 
    {
        dp.resize(n+1,vector<int>(W+1,-1));                          // Fixing the size of DP matrix & initializing it.
        
        return solve(W,wt,val,n);
        
    }
};

int main()
{
    vector<int> weights = {1,1,1};
    vector<int> values = {10,20,30};
    int n = 3;
    int capacity = 2;

    Solution S1;

    int ans = S1.knapSack(capacity,weights,values,n);

    cout << ans << endl;
}