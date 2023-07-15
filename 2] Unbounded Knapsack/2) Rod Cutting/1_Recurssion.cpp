#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :
      
    int solve(vector<int> prices, int n, int Length)
    {
        // Base Condition
        if( n==0 || Length==0) return 0;
        
        // Choice Diagram
        if(n <= Length)
        {
            return max(prices[n-1] + solve(prices,n,Length-n), solve(prices,n-1,Length));
        }
        else
        {
            return solve(prices,n-1,Length);
        }
     
    }
    
    
    int cutRod(vector<int> prices, int n)
    {
        int Length = n;
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