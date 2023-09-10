#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:

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

        int low,mid,high,Break,Survive;
        
        for(int i = 2 ; i <= e ; i++)            // i => Eggs
        {
            for(int j = 2 ; j <= f ; j++)        // j => Floors
            {
                final_ans = INT_MAX;
                low = 1;
                high = j;
                while(low <= high)
                {
                    mid = (low+high)/2;

                    Break = dp[i-1][mid-1];
                    Survive = dp[i][j-mid];                                       

                    temp_ans = 1 + max(Break,Survive);
                    final_ans = min(temp_ans,final_ans);
                
                    if(Break > Survive) high = mid-1;
                    else low = mid+1;
                }

                dp[i][j] = final_ans;
            }
        }

        return dp[e][f];

    }

    int eggDrops(int e, int f)
    {
        dp.resize(e+1,vector<int>(f+1,0));
        return solve(e,f);
    }
};

int main()
{
    int Floors, Eggs;
    cout << "Floors : ";
    cin >> Floors;
    cout << "Eggs : ";
    cin >> Eggs;

    Solution S;

    cout << "Answer : " << S.eggDrops(Eggs,Floors) << endl;
}

/*
1. It is submitted successfully on Leetcode.
2. The thing to observe is that, it takes significant amount of more time than even our "Memoizied Code".
3. Whereas "Tabulation" (Bottom - UP), should be faster than our "Memoization" (Top - Down).

Why this happens?

1. This is not the case of just "Egg Dropping" problem.
2. This happens for all the questions whose parent question is "MCM".
3. The thing with MCM pattern question is, we already have a loop (for/while) in which we are making Recurssive calls.  
4. Now when we do tabulation we require a "Nested For Loop" to traverse our DP matrix.
5. We put all our recursive logic inside this "Nested For Loop". 
6. As a result now we have 3 Loops present in Nested form.
7. Now our time complexity become O(N³).                                                                                    // ¹²³⁴⁵⁶⁷⁸⁹⁰

So Tabulation is not really helping us in MCM Pattern questions.
*/