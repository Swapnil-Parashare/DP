#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution 
{
    public : 

    vector<vector<bool>> dp;

    bool solve(vector<int>& arr, int n, int sum)
    {
        // Initilization
        for(int j = 0 ; j <= sum ; j++) dp[0][j] = false;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = true;

        // Choice Diagram

        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= sum ; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }

    bool equalPartition(vector<int>& arr, int n)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum % 2 != 0) return false;
        sum /= 2;

        dp.resize(n+1,vector<bool>(sum+1));

        return solve(arr,n,sum);
    }
};

int main()
{
    vector<int> arr = {1,5,11,5};
    Solution S1;

    cout << S1.equalPartition(arr, arr.size()) << endl;
}