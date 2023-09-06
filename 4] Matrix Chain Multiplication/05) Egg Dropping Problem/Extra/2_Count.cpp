#include <iostream>
#include <vector>

using namespace std;

                                /* Observe, how many Recursive Calls are saved because of Memoization. */  
                                   // Memoization : To avoid solving of "Repeatitive Subproblems"
class Solution
{
    public :

    int Recursion_Count = 0;
    int Memoization_Count = 0;

    
    int R_Solve(int e, int f) 
    {   

        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        Recursion_Count++;

        int temp_ans;
        int final_ans = INT_MAX;

        for(int k = 1 ; k <= f ; k++)
        {
            temp_ans = 1 + max(                                       // Maximum is taken, because we are considering worst case.
                            R_Solve(e-1,k-1),                         // Break
                            R_Solve(e, f-k)                           // Not Break
                         ); 

            final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts in all the "Worst Cases". (Chossing Best from the Worst)
        };

        return final_ans;
    }
 
    vector<vector<int>> dp;
    
    int M_Solve(int e, int f) 
    {
        
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        // Memoization
        if(dp[e][f] != -1) return dp[e][f];
        
        Memoization_Count++;

        int temp_ans;
        int final_ans = INT_MAX;

        for(int k = 1 ; k <= f ; k++)
        {
            temp_ans = 1 + max(                                       // Maximum is taken, because we are considering worst case.
                            M_Solve(e-1,k-1),                           // Break
                            M_Solve(e, f-k)                             // Not Break
                         ); 

            final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts in all the "Worst Cases".
        };

        return dp[e][f] = final_ans;
    }

    int eggDrop(int e, int f) 
    {
        dp.resize(e+1,vector<int>(f+1, -1));
        return M_Solve(e,f);
    }
    

    
};


int main()
{
    int floors = 30;
    int eggs = 2;

    Solution S;

    // (Eggs, Floors)

    cout << "\n\nRecursion Answer   : " << S.R_Solve(eggs,floors) << endl;

    cout << "Memoization Answer : " << S.eggDrop(eggs,floors) << endl;

    cout << "\nObserve the reduction in Recurssive Function Calls because of Memoization\n" << endl;

    cout << "Recursion Function Calls   : " << S.Recursion_Count << endl;
    cout << "Memoization Function Calls : " << S.Memoization_Count << endl;

    cout << endl;

}

/*

(Note : i]We are only counting the function calls were actual computation is done. 
       ii]We are not counting the function calls were answer would be return directly from base case or Memoization condition.)

1] Number of Function calls made in Recursion is very very huge as compared to that of Memoization.
2] This is because, this is a MCM pattern Question.
3] Here, " We are dividing our main problem into subproblems, in multiple ways, Recursively!!!! "
   Read it again :- 1] Dividing main problem into subproblems.
                    2] In Multiple ways.
                    3] Recursively.
                    Let that sink in......
4] In normal recursion problem we just divide main problem into problems, recursively.
                    1] Divide main problem into subproblems.
                    2] Recursively.
    Here we have only one way in which our main problem can be divided into subproblems.
*/



