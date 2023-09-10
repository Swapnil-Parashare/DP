#include<iostream>
#include<vector>
#include<cmath>

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
        // Base Condition
        if(e == 1 || f == 0 || f == 1)
        {
            return f;
        }

        // Memoization
        if(dp[e][f] != -1) return dp[e][f];
        

        // If Sufficient amount of eggs are present.
        int sufficient = log2(f) + 1;
        if(e >= sufficient) return sufficient;


        int temp_ans;
        int final_ans = INT_MAX;

        int low,mid,high,Break,Survive;
        low = 1;
        high = f;

        while(low <= high)
        {
            mid = (low+high)/2;

            Break = solve(e-1,mid-1);
            Survive = solve(e,f-mid);                                       

            temp_ans = 1 + max(Break,Survive);
            final_ans = min(temp_ans,final_ans);
        
            if(Break > Survive) high = mid-1;
            else low = mid+1;
            
        }

        return dp[e][f] = final_ans;
    }

    int eggDrops(int e, int f)
    {
        dp.resize(e+1,vector<int>(f+1,-1));
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
1. Better than Tabulation.
2. We can add the sufficient egg condition, inside nested for loops of tabulation.
3. But I am keeping it as it is. 
4. It reduces the readablity of the code.

Here it won't affect that much. As we can simply consider it as another base condition.
*/