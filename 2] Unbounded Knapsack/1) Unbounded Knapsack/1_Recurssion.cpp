#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:

    int knapSack(vector<int> weights, vector<int> values, int n, int W) 
    { 
        
       // Base Condition
       if( W == 0 || n == 0 )
       {
           return 0;
       }
       
       // Choice Diagram
       
       if(weights[n-1] <= W)
       {
           return 
           max(
           values[n-1] + knapSack(weights, values, n, W-weights[n-1])          // Include        (Not moving to previous item. i.e NOT PROCESSED)
                                    ,
                         knapSack(weights,values,n-1,W)                        // Don't Include
            );
       }
       else
       {
           return knapSack(weights,values,n-1,W);                               // Don't Include
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

    int ans = S1.knapSack(weights,values,n,capacity);

    cout << ans << endl;
}