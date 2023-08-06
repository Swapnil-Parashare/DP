#include <iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    vector<int> arr;
    vector<vector<int>> dp;

    int solve(int i , int j)
    {
        // Base Condition

        if(i == j)
        {
            return 0;
        }

        // Memoization
        if(dp[i][j] != -1) return dp[i][j];

        int final_ans = INT_MAX;
        int temp_ans;

        // Breaking Problem in Multiple ways.
        for(int k = i ; k < j ; k++)
        {
            temp_ans = solve(i,k) + solve(k+1,j) + (arr[i-1] * arr[k] * arr[j]);      

            final_ans = min(final_ans,  temp_ans);        
        }

        return dp[i][j] = final_ans;
    }
    
    int matrixMultiplication(int N, vector<int> arr)
    {
        this->arr = arr;

        int i = 1;
        int j = N - 1;

        dp.resize(N,vector<int>(N,-1));

        return solve(i,j);
    }

};

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30};

    Solution S;

    cout << "Minimum Cost : " << S.matrixMultiplication(arr.size(),arr) << endl;
}