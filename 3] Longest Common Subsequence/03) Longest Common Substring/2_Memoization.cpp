#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    string s1;
    string s2;

    vector<vector<vector<int>>> dp;                   // 3 Dimensional DP matrix is used. Because 3 inputs of Recurssion are changing.

    int solve(int m, int n, int count)
    {
        // Base Condition
        if(m == 0 || n == 0)
        {
            return count;                            // Return whatever is the count till now.
        }

        // Memoization
        if(dp[m][n][count] != -1) return dp[m][n][count];
        

        // Choice Diagram
        if(s1[m-1] == s2[n-1])
        {
            return dp[m][n][count] = max( solve(m-1,n-1,count + 1), max(solve(m-1,n,0), solve(m,n-1,0)));
        }
        else
        {
            return dp[m][n][count] = max(count, max(solve(m-1,n,0), solve(m,n-1,0)));
        }
    }

    int substring(string s1, string s2, int m, int n)
    {
        // Just making strings accessible to any "Member Function". Just like Global.
        this->s1 = s1;     
        this->s2 = s2;

        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(1001,-1)));

        return solve(s1.size(), s2.size(), 0);
    }
};

int main()
{
    string s1 = "zypqrxabcd";
    string s2 = "mzypqrabcd";

    Solution S;

    cout << S.substring(s1,s2,s1.size(), s2.size()) << endl;

}