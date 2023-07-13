#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    
    vector<vector<int>> dp;                                         // Global DP Matrix
    
    int solve(int W, vector<int> wt, vector<int> val, int n) 
    { 
        
       // Initialization
       for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
       for(int j = 0 ; j <= W ; j++) dp[0][j] = 0;
       
       for(int i = 1 ; i <= n ; i++)
       {
           for(int j = 1 ; j <= W ; j++ )
           {
               // Choice Diagram
               if(wt[i-1] <= j)
                {
                    dp[i][j] = max(
                    val[i-1] + dp[i-1][j-wt[i-1]]                 // Include
                                             ,
                               dp[i-1][j]                         // Don't Include
                     );
                }
                else
                {
                    dp[i][j] = dp[i-1][j];                        // Don't Include
                }
            }
       } 
       return dp[n][W];
    }
    
    
    int knapSack(int W, vector<int> wt, vector<int> val, int n) 
    {
        dp.resize(n+1,vector<int>(W+1));
        
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