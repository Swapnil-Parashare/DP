#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public :

    vector<vector<int>> dp;
    
    int solve(int e, int f) 
    {
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        // Memoization
        if(dp[e][f] != -1) return dp[e][f];


        int temp_ans;
        int final_ans = INT_MAX;

        for(int k = 1 ; k <= f ; k++)
        {
            temp_ans = 1 + max(                                       // Maximum is taken, because we are considering worst case.
                            solve(e-1,k-1),                           // Break
                            solve(e, f-k)                             // Not Break
                         ); 

            final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts in all the "Worst Cases".
        };

        return dp[e][f] = final_ans;
    }

    int eggDrop(int e, int f) 
    {
        dp.resize(e+1,vector<int>(f+1, -1));
        return solve(e,f);
    }
    
};


int main()
{
    int eggs = 2;
    int floors = 10;

    Solution S;

    // (Eggs, Floors)

    cout << "Attempts : " << S.eggDrop(eggs,floors) << endl;
}