#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    string s1;
    string s2;               // Reverse of 's1'. As we have to find LPS.
    vector<vector<int>> dp;

    /********************************   Longest Common Subsequence     *************************************/

    int lcs(int m, int n)                // LPS(str) = LCS(str, reverse(str));
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
        return dp[m][n];                       // Length of LPS is returned.
    }
    /******************************************************************************************************/

    int minInsertions(string str, int n)
    { 
        string s1 = str;
        string s2 = string(s1.rbegin(), s1.rend());
        int m = n;

        this->s1 = s1;
        this->s2 = s2;
        dp.resize(m+1,vector<int>(n+1));

        int insertions = str.size() - lcs(m,n);

        return insertions;
    } 

};

int main()
{

    string str = "AEBCBDA" ;

    Solution S;

    int ans = S.minInsertions(str,str.size());

    cout << "Insertions : " << ans << endl;
}