#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:

    int knapSack(int W, vector<int> wt, vector<int> val, int n) 
    { 
        
       // Base Condition
       if( W == 0 || n == 0 )
       {
           return 0;
       }
       
       // Choice Diagram
       
       if(wt[n-1] <= W)
       {
           return 
           max(
           val[n-1] + knapSack(W-wt[n-1], wt, val, n-1)                 // Include
                                    ,
                             knapSack(W, wt,val,n-1)                    // Don't Include
            );
       }
       else
       {
           return knapSack(W,wt,val,n-1);                               // Don't Include
       }
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