#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public :

    string s1;
    string s2;
    vector<vector<int>> dp;

    string solve(int m, int n)
    {

        /**********************     LCS Tabulation (Bottom-UP) Code     *************************/

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
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
                }
            }
        }

        /****************************************************************************************/

        // Tracing DP Matrix in Reverse order in a pattern to print LCS.

        int i = m;
        int j = n;
        string ans;

        while(i > 0 && j > 0)
        {
            if(s1[i-1] == s2[j-1])
            {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i-1][j] > dp[i][j-1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string lcs(string s1, string s2, int m, int n)
    {
        this->s1 = s1;
        this->s2 = s2;
        dp.resize(m+1,vector<int>(n+1));
        return solve(m,n);
    }
};

int main()
{
    string s1 = "ajcmxyz";
    string s2 = "tacnxyz";

    Solution S;

    cout << S.lcs(s1,s2,s1.size(),s2.size()) << endl;

}