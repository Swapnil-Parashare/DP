#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:

    vector<vector<int>> dp;

    // This calculates log to the base 2, in constant time. (Bit Manipulation)
    int log(long long x) 
    {
        return 64 - __builtin_clzl(x) - 1;
    }

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
        int sufficient;
        
        for(int i = 2 ; i <= e ; i++)            // i => Eggs
        {
            for(int j = 2 ; j <= f ; j++)        // j => Floors
            {

                sufficient = log(j) + 1;
                if(i >= sufficient)
                {
                    dp[i][j] = sufficient;
                    continue;
                }

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
