#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
    public :

    vector<vector<int>> dp;
    
    int solve(int e, int f) 
    {
        // Initializaton
        for(int j = 0 ; j <= f ; j++) dp[1][j] = j;             // One Egg is left.
        for(int i = 1 ; i <= e ; i++)
        {
            dp[i][0] = 0;                                       // Zero Floors are left.
            dp[i][1] = 1;                                       // One Floor is left.
        }


        int temp_ans;
        int final_ans;

        for(int i = 2 ; i <= e ; i++)            // i => Eggs
        {
            for(int j = 2 ; j <= f ; j++)        // j => Floors
            {

                if(i >= log2(j)+1 )              // Plenty eggs are present, use binary search.
                {
                    dp[i][j] = log2(j) + 1;
                    continue;
                }

                final_ans = INT_MAX;
                for(int k = 1 ; k <= j ; k++)
                {
                    temp_ans = 1 + max(                                       // Maximum is taken, because we are considering worst case.
                                    dp[i-1][k-1],                             // Break
                                    dp[i][j-k]                                // Not Break
                                 ); 

                    final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts in all the "Worst Cases". (Chossing Best from the Worst)
                }    
                dp[i][j] =  final_ans;
            }
        }
        return dp[e][f];
    }

    int eggDrop(int e, int f) 
    {

        dp.resize(e+1,vector<int>(f+1,0));
        return solve(e,f);
    }
};


int main()
{
    int floors = 100;
    int eggs = 2;

    Solution S;

    cout << "Attempts : " << S.eggDrop(eggs,floors) << endl;
}


// More Optimization is expected on leetcode.
