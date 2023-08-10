#include <iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    vector<int> arr;
    int N;
    vector<vector<int>> dp;

    int solve()
    {
        // Initialization
        for(int i = 1 ; i < N ; i++)
        {
            dp[i][i] = 0;
        }

        // Nested For-Loop to trace the DP Matrix.

        int final_ans;
        int temp_ans;

        for(int i = N-2 ; i >= 1 ; i--)                     
        {
            for(int j = i+1 ; j < N ; j++)
            {
                final_ans = INT_MAX;

                // Breaking Problem in Multiple ways.
                for(int k = i ; k < j ; k++)
                {
                    temp_ans = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);      

                    final_ans = min(final_ans,  temp_ans);        
                }
                dp[i][j] = final_ans;
            }
        }
        return dp[1][N-1];    
    }
    
    int matrixMultiplication(int N, vector<int> arr)
    {
        this->arr = arr;
        this->N = N;


        dp.resize(N,vector<int>(N));

        return solve();
    }

};

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30};

    Solution S;

    cout << "Minimum Cost : " << S.matrixMultiplication(arr.size(),arr) << endl;
}