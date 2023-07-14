#include<iostream>
#include<vector>
#include<numeric>


using namespace std;

class Solution
{
    public : 

    vector<vector<bool>> dp;


    // Subset Sum Problem.
    bool subsetSum(vector<int>& arr, int n, int sum)
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


    // Little Logic on top of it.
    int minDifference(vector<int>& arr, int n)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        dp.resize(n+1,vector<bool>(sum+1));

        subsetSum(arr,n,sum);                      // Filling our DP Matrix.

        vector<int> validSubsetSum;

        for(int j = 0 ; j <= sum ; j++)
        {
            if(dp[n][j] == true)
            {
                validSubsetSum.push_back(j);
            }
        }

        int size = validSubsetSum.size();

        if(size%2 != 0) return 0;                // This is S1 == S2 case. (i.e Equal Sum Partition). Thus Minimum Difference is 0.

        return sum  - 2*validSubsetSum[size/2 - 1];
    }


};

int main()
{
    vector<int> arr = {1,6,11,5};

    Solution S1;

    cout << S1.minDifference(arr,arr.size()) << endl;
}