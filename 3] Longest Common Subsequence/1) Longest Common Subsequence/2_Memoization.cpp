#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :

    vector<vector<int>> dp;

    int solve(string s1, string s2, int m, int n)
    {
        // Base Condition
        if( m==0 || n==0 )
        {
            return 0;
        }

        // Memoizaion
        if(dp[m][n] != -1) return dp[m][n];

        // Choice Diagram
        if(s1[m-1] == s2[n-1])
        {
            return dp[m][n] = 1 + solve(s1,s2,m-1,n-1);
        }
        else
        {
            return dp[m][n] = max(solve(s1,s2,m,n-1), solve(s1,s2,m-1,n));
        }
    }

    int lcs(string s1, string s2, int m, int n)
    {
        dp.resize(m+1,vector<int>(n+1,-1));
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