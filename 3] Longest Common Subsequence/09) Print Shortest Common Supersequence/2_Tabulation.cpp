#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/************   Method 2 : Print SCS    ***************/


class Solution
{
    public : 

    string s1;
    string s2;
    vector<vector<int>> dp;

    /*********************************     Function to find Lenght of LCS (Bottom-Up)   **************************************/
    
    
    void lcs(int m, int n)                                                // This Function will fill our DP matrix.
    {
        // Initialization
        for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
        for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;

        //Choice Diagram
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
                    dp[i][j] = max(dp[i][j-1] ,dp[i-1][j]);
                }
            }
        }
    }

    string print_lcs(int m, int n)                                       // This function will give actual LCS.
    {
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
                if(dp[i][j-1] > dp[i-1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string print_scs(int m, int n, string lcs)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        int lcs_size = lcs.size();

        string scs;

        while( k < lcs_size)
        {

            while(s1[i] != lcs[k] )
            {
                scs.push_back(s1[i]);
                i++;
            }

            while(s2[j] != lcs[k])
            {
                scs.push_back(s2[j]);
                j++;
            }

            scs.push_back(lcs[k]);
            i++;
            j++;
            k++;
            
        }

        // Print remaining elements
        while(i < m)
        {
            scs.push_back(s1[i]);
            i++;
        }
        while(j < n)
        {
            scs.push_back(s2[j]);
            j++;
        }

        return scs;
    }
    

    string shortestCommonSupersequence(string s1, string s2)
    {
        this->s1 = s1;
        this->s2 = s2;

        int m = s1.size();
        int n = s2.size();

        dp.resize(m+1,vector<int>(n+1));

        lcs(m,n);                                 // This will fill DP matrix.
        string lcs = print_lcs(m,n);              // Here we will get actual LCS, using DP matrix.
        string scs = print_scs(m,n,lcs);          // Here we will get SCS, using LCS.

        return scs;
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