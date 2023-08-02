#include<iostream>
#include<vector>

using namespace std;

/* IMP :-
1] This solution has nothing to do with our Recursive Approach.
2] We have not done Recurrsion ---to---> Tabulation (Bottom-Up).
3] This is different approach.
4] We are just smartly using 2D Matrix to get the answer.
*/


class Solution
{
    public : 

    vector<vector<int>> dp;
    
    int substring(string s1, string s2, int m, int n)
    {
        dp.resize(m+1,vector<int>(n+1,0));      
        
        int ans = 0;

        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(s1[i-1] == s2[j-1]) 
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);                   // Calculating the maximum while iterating itself.
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

int main()
{
    string s1 = "lmndpqruxyzij";
    string s2 = "abuxyznrmndo";

    Solution S;

    cout << S.substring(s1,s2,s1.size(), s2.size()) << endl;

}