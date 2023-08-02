#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :

    vector<vector<int>> dp;

    int solve(string s1, string s2, int m, int n)
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
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }

        return dp[m][n];
    }

    int lcs(string s1, string s2, int m, int n)
    {
        dp.resize(m+1,vector<int>(n+1));
        return solve(s1,s2,m,n);
    }
    
};

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    int m = s1.size();
    int n = s2.size();

    Solution S1;

    cout << S1.lcs(s1,s2,m,n) << endl;
}