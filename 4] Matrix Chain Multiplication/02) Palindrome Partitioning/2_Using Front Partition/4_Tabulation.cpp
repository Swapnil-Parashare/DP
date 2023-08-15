#include<iostream>
#include<vector>

using namespace std;

/* Fun Fact : This Tabulation takes more time (0.74 Secs) than our Memoized Code (0.01)*/

class Solution
{
    public:

    string str;
    int N;
    vector<vector<int>> dp;

    bool isPalindrome(int i, int j)
    {
        bool ans = true;

        while( i < j)
        {
            if(str[i] != str[j])
            {
                ans = false;
                break;
            }
            i++;
            j--;
        }

        return ans;
    }

    int solve(int i, int j)
    {
        // Initialization
        for(int i = 0 ; i < N ; i++) dp[i][i] = 0;
        
        int final_ans;
        int temp_ans;

        // Creating a seprate Palindrome DP.

        

        for(int i = N-2 ; i >= 0 ; i--)
        {
            for(int j = i+1 ; j < N ; j++)
            {
                if(isPalindrome(i,j))
                {
                    dp[i][j] = 0;
                    continue;
                }

                final_ans = INT_MAX;
                
                for(int k = i ; k < j ; k++)
                {
                    if(isPalindrome(i,k))
                    {
                        temp_ans = 1 + dp[k+1][j] ;
                        final_ans = min(temp_ans, final_ans);
                    }
                }

                dp[i][j] = final_ans;

            }
        }

        return dp[i][j];
        
    }
    
    int palindromicPartition(string str)
    {
        this->str = str;
        this->N = str.size();

        int size = str.size();
        int i = 0;
        int j = size - 1;

        dp.resize(size,vector<int>(size));


        return solve(i,j);
    }
};


int main()
{
    string str = "xiiy";

    Solution S;

    cout << "Minimum Partitions : " << S.palindromicPartition(str) << endl; 
}