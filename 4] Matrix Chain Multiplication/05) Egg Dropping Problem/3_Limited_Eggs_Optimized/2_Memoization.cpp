#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    
    vector<vector<int>> dp;

    int solve(int e, int f)
    {
        // Base Condition
        if(e == 1 || f == 0 || f == 1)
        {
            return f;
        }

        // Memoization
        if(dp[e][f] != -1) return dp[e][f];

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