#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 
    string s1;
    string s2;
    vector<vector<int>> dp;



    int solve(int m, int n)
    {

        /***************************    LCS Tabulation Code (Bottom-Up)     ****************************/

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
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        /*********************************************************************************************/

        int lcs = dp[m][n];
        
        int scs = m + n - lcs;

        return scs;
    }



    int scs(string s1, string s2, int m, int n)
    {
        this->s1 = s1;
        this->s2 = s2;
        dp.resize(m+1,vector<int>(n+1));
        return solve(m,n);
    }
};

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    Solution S;

    cout << S.scs(s1,s2,s1.size(),s2.size()) << endl;
}