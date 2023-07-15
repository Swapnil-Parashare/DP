#include<iostream>
#include<vector>

using namespace std;

class Solution{
  public:
  
    vector<vector<int>> dp;
  
    int solve(vector<int> price, int n, int Length)
    {
        // Base Condition
        if( n==0 || Length==0) return 0;
        
        // Memoization
        if(dp[n][Length] != -1) return dp[n][Length];
        
        // Choice Diagram
        if(n <= Length)
        {
            return dp[n][Length] = max(price[n-1] + solve(price,n,Length-n), solve(price,n-1,Length));
        }
        else
        {
            return dp[n][Length] = solve(price,n-1,Length);
        }
     
    }
    
    
    int cutRod(vector<int> price, int n) {
        int Length = n;
            
        dp.resize(n+1,vector<int>(Length+1,-1));
        return solve(price,n,Length);
    }
};

int main()
{
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();                                         

    Solution S1;

    cout << S1.cutRod(prices,n) << endl;
}