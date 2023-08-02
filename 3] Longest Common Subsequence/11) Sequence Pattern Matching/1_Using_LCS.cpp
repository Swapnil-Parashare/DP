#include<iostream>
#include<vector>

using namespace std;

/******************     There is no need to use LCS to solve this problem, but lets see how it can be done.     **************/

// Note : This approach gives TLE.

class Solution
{
    public : 
    string s1;
    string s2;
    vector<vector<int>> dp;

    /******************     LCS (Bottom-Up) Code    ***************/

    int lcs(int m, int n)
    {
        // Initialization
        for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
        for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;

        // Choice Diagram
        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }

    /**************************************************************/


    bool isSubsequence(string A, string B)          // Wheather 'B' is present as a subsequence in 'A' OR Viceversa
    {
        this->s1 = A;
        this->s2 = B;

        int m = A.size();
        int n = B.size();

        dp.resize(m+1,vector<int>(n+1));

        int lcs_size = lcs(m,n);

        if(lcs_size == min(m,n))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};

int main()
{
    string A = "ADXCPY";
    string B = "AXY";

    Solution S;


    cout << S.isSubsequence(A,B) << endl;
}