#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    vector<vector<bool>> dp;

    bool solve(vector<int>& arr, int n, int sum)
    {
        // Initialization
        for(int j = 0 ; j <= sum ; j++) dp[0][j] = false;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = true;

        // Choice Diagram
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= sum ; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j - arr[i-1]]  || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }

    int subsetSum(vector<int>& arr, int n, int sum)
    {
        dp.resize(n+1,vector<bool>(sum+1));
        return solve(arr,n,sum);
    }


};

int main()
{
    vector<int> arr = {2,3,5,8,11};
    int sum = 12;
    int n = arr.size();

    Solution S1;

    bool ans = S1.subsetSum(arr,n,sum);

    cout << ans << endl;

}