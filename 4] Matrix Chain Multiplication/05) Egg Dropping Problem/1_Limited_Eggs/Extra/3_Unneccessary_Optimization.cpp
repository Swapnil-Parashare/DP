#include <iostream>
#include <vector>

using namespace std;


// Optimization in Memoized Code. Not truly worth it.


class Solution1
{
    public :
    int count = 0;


    vector<vector<int>> dp;
    
    int solve(int e, int f) 
    {
        count++;

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


/* Minor Optimization.  Checking subproblems, wheather they are solved or not.
But it is not really significant. Not worth doing it. But why its not worth it? Lets see. */

class Solution2
{
    public :
    int count = 0;

    vector<vector<int>> dp;
    
    int solve(int e, int f) 
    {
        count++;

        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        // Memoization
        if(dp[e][f] != -1) return dp[e][f];


        int temp_ans;
        int final_ans = INT_MAX;
        int left, right;

        for(int k = 1 ; k <= f ; k++)
        {
            
            /*********  Checking Subproblems    ********/

            if(dp[e-1][k-1] != -1) left = dp[e-1][k-1];            // Break
            else left = solve(e-1,k-1);

            if(dp[e][f-k] != -1) right = dp[e][f-k];               // Survive
            else right = solve(e,f-k);

            /*******************************************/

            temp_ans = 1 + max( left, right); 

            final_ans = min(final_ans,temp_ans);                    
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
    int floors = 30;

    Solution1 S1;

    cout << endl;

    cout << "Attempts : " << S1.eggDrop(eggs,floors) << endl;
    cout << "Count : " << S1.count << endl;

    cout << "\n" << endl;

    Solution2 S2;

    cout << "Attempts : " << S2.eggDrop(eggs,floors) << endl;
    cout << "Count : " << S2.count << endl;

    cout << endl;

    /*
                            Note : This is not a very big optimization.

    1] Lets say we didn't check whether subproblems (left, right) are solved or not. What will happen?
    2] A function call will be made.
    3] Now if the problem is already solved, we will obviously hit our Memoization condition & answer will be return there itself. 
    4] We won't solve the whole problem again. 
    5] What we are achieving by checking of subproblems is just the elimination of functions.
    6] We are not saving any computational work. Because we was not going to compute that function anyway.

    Now if you count the number of functions calls made. You may see very large difference.
    Nearly half amount of functions calls are reduced.
    But don't let it confuse you.
    We are not saving any extra computation here.
    We are just preventing invokation & not the computation. (Computation was not going to happen anyway.)


    Fun Fact : 1] If you place the counter below the "Memoization Condition" instead of placing it above "Base Condition",
                  You will see that same number of function calls are made in both the cases.
               
               2] This is because in unsolved problem, where computation is required, control will reach below the "Memoization Condition" for sure.
                  Just making the function call and returning the answer without doing any computation won't happen in this case.

    */


}