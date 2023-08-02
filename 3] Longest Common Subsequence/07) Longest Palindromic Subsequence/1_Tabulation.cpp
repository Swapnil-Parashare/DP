#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 
    string s1;
    string s2;
    vector<vector<int>> dp;

    /******************************     LCS Tabulation Code (Bottom-Up)     **************************/

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

    /*****************************************************************************************************/

    int lps(string s1)
    {
        string s2 = string(s1.rbegin(), s1.rend());       // Reversing orignal string.

        this->s1 = s1;
        this->s2 = s2;

        int m;
        int n;
        m = n = s1.size();

        dp.resize(m+1,vector<int>(n+1));

        int lps_size = lcs(m,n);

        return lps_size;
    }
};

int main()
{
    string s1 = "agbcba";

    Solution S;

    int ans = S.lps(s1);

    cout << "Answer : " << ans << endl;

}