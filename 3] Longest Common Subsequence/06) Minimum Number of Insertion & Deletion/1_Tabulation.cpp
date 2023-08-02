#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public : 

    string s1;
    string s2;
    vector<vector<int>> dp;

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
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }

    int solve(string s1, string s2, int m, int n)
    {
        this->s1 = s1;
        this->s2 = s2;
        dp.resize(m+1,vector<int>(n+1));

        int lcs_size = lcs(m,n);
        int deletions = m - lcs_size;
        int insertions = n - lcs_size;

        return deletions + insertions;
    }

};

int main()
{
    string s1 = "aocmxyz";
    string s2 = "jacnxyz";

    Solution S;

    int answer = S.solve(s1,s2,s1.size(),s2.size());

    cout << "\nNo of Operations : " << answer << endl;
}