#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution
{
    public :

	const long long int limit = 1e9+7;

    vector<vector<int>> dp;

    int solve(vector<int>& arr, int n, int sum)
    {
        // Initialization
        for(int j = 0 ; j <= sum ; j++) dp[0][j] = 0;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
        


        // Choice Diagram
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= sum ; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % limit;
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }

    int perfectSum(vector<int>& arr, int n, int sum)
    {



        // Tackling the presence of ZERO in more optimized way.

        vector<int> vec;
        int zeroCount = 0;

        for(int i = 0 ; i < n ; i++)                          // Removing 0's
        {
            if(arr[i] != 0) vec.push_back(arr[i]);
            else zeroCount++;
        }

        n = vec.size();                                       // Updating size of new array.


        dp.resize(n+1,vector<int>(sum+1));

        int ansWithoutZero = solve(vec,n,sum);

        return ansWithoutZero * pow(2,zeroCount);
    }
};

int main()
{
    vector<int> arr = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    int n = arr.size();
    int sum = 31;

    Solution S1;

    cout << S1.perfectSum(arr,n,sum) << endl;
}