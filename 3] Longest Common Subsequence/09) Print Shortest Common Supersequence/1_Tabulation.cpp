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

/*********************************************    LCS Tabulation Code (Bottom-Up)     *****************************************/

    // We need the DP Table of LCS to solve this problem
    void lcs(int m, int n)
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
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }

    /**************************************************************************************************************************/



    /*****************************   Code Similar to Print LCS with minor changes    ******************************************/
    string print_scs(int m, int n)  
    {
        int i = m;
        int j = n;

        string ans;

        while( i > 0 && j > 0)                      // IMP : First Print & then move. Whatever may be the case.
        { 
            if(s1[i-1] == s2[j-1])
            {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    ans.push_back(s1[i-1]);             // Print the Left ( i.e where are not moving.)
                    i--;                                // Move to Upper (i.e Max)
                }
                else
                {
                    ans.push_back(s2[j-1]);             // Print the Upper (i.e where we are not moving.)
                    j--;                                // Move to Left (i.e Max)
                }
            }
        }

        // Print the rest of the String when 0 is encountered.
        while(i > 0)
        {
            ans.push_back(s1[i-1]);
            i--;
        }

        while(j > 0)
        {
            ans.push_back(s2[j-1]);
            j--;
        }

        // Reversing the Final Answer.
        reverse(ans.begin(), ans.end());

        return ans;

    }

    /**************************************************************************************************************************/

    string shortestCommonSupersequence(string str1, string str2)
    {
        this->s1 = str1;
        this->s2 = str2;

        int m = str1.size();
        int n = str2.size();
        dp.resize(m+1,vector<int>(n+1));

        lcs(m,n);                                 // Here our DP Table of LCS will get filled.

        string ans = print_scs(m,n);

        return ans;

    }
};

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    Solution S;

    string ans = S.shortestCommonSupersequence(s1,s2);

    cout << "SCS : " << ans << endl;
}