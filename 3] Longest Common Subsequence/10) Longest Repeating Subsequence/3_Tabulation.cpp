#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    string s1;
    string s2;
    vector<vector<int>> dp;

    int lrs(int m, int n)
    {
        // Initialization
        for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
        for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;

        // Choice Diagram
        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if((s1[i-1] == s2[j-1]) && (i!=j) )
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max( dp[i][j-1] , dp[i-1][j] );
                }
            }
        }

        return dp[m][n];
    }

    int LongestRepeatingSubsequence(string str)
    {
        this->s1 = str;
        this->s2 = str;

        int m = str.size();
        int n = str.size();
        dp.resize(m+1,vector<int>(n+1));

        int ans = lrs(m,n);

        return ans;
    }
};

int main()
{
    string str = "AABEBCDD";
    Solution S;
    cout << S.LongestRepeatingSubsequence(str) << endl;
}