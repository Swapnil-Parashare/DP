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
        // Base Condition
        if(m == 0 || n == 0) 
        {
            return 0;
        }

        // Memoization
        if(dp[m][n] != -1) return dp[m][n];

        // Choice Diagram
        if( (s1[m-1] == s2[n-1]) && (m!=n) )
        {
            return dp[m][n] = 1 + lrs(m-1,n-1);
        }
        else
        {
            return dp[m][n] = max( lrs(m,n-1) , lrs(m-1,n) );
        }
    }

	int LongestRepeatingSubsequence(string str)
    {
	    this->s1 = str;
        this->s2 = str;

        int m = str.size();
        int n = str.size();
        dp.resize(m+1,vector<int>(n+1,-1));

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