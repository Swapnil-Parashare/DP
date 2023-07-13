#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    vector<vector<int>> dp;

    bool solve(vector<int>& arr, int n, int sum)
    {
        // Base Condition
        if(sum == 0) return true;
        if(n == 0) return false;

        // Memoization
        if(dp[n][sum] != -1) return dp[n][sum];

        // Choice Diagram
        if(arr[n-1] <= sum)
        {
           return  dp[n][sum] = solve(arr,n-1,sum - arr[n-1]) || solve(arr,n-1,sum);
        }
        else
        {
            return dp[n][sum] = solve(arr,n-1,sum);
        }
    }

    int subsetSum(vector<int>& arr, int n, int sum)
    {
        dp.resize(n+1,vector<int>(sum+1, -1));
        return solve(arr,n,sum);
    }


};

int main()
{
    vector<int> arr = {2,3,5,8,11};
    int sum = 11;
    int n = arr.size();

    Solution S1;

    cout << S1.subsetSum(arr,n,sum) << endl;
}