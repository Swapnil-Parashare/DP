#include <iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    vector<int> arr;

    int solve(int i , int j)
    {
        // Base Condition

        if(i == j)
        {
            return 0;
        }

        int final_ans = INT_MAX;

        // Breaking Problem in Multiple ways.
        for(int k = i ; k < j ; k++)
        {
            int cost_1 = solve(i,k);                         // Minimum Cost returned by Sub-problem 1
            int cost_2 = solve(k+1,j);                       // Minimum Cost returned by Sub-problem 2
            int cost_3 = arr[i-1] * arr[k] * arr[j];         // Cost of multiplying Resultant Matrices of Sub-Problem 1 & Sub-Problem 2.

            int temp_ans = cost_1 + cost_2 + cost_3;         // Operation done on answers returned by Sub-Problem.

            final_ans = min(final_ans, temp_ans);            // Additional Operation to convert Temporary answer to Final answer.
        }

        return final_ans;
    }
    
    int matrixMultiplication(int N, vector<int> arr)
    {
        this->arr = arr;

        int i = 1;
        int j = N - 1;

        return solve(i,j);
    }

};

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30};

    Solution S;

    cout << "Minimum Cost : " << S.matrixMultiplication(arr.size(),arr) << endl;
}