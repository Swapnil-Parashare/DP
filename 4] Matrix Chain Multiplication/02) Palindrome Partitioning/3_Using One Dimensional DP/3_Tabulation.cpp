#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :

    string str;
    int N;
    vector<int> dp;

    bool isPalindrome(int i , int j)
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

    int solve(int i)
    {
        // Initialization
        dp[N-1] = 0;

        int final_ans;
        int temp_ans;

        for(int i = N-2 ; i >= 0 ; i--)               // Traversing DP.
        {

            if(isPalindrome(i,N-1)) 
            {
                dp[i] = 0;
                continue;
            }

            final_ans = INT_MAX;

            for(int k = i ; k < N-1 ; k++)            // Partitioning.
            {
                if(isPalindrome(i,k))
                {
                    temp_ans = 1 + dp[k+1];
                    final_ans = min(temp_ans,final_ans);
                }
            }
            dp[i] = final_ans;    
        }

        return dp[0];

    }

    int palindromicPartition(string str)
    {
        this->str = str;
        this->N = str.size();

        dp.resize(N);
        int i = 0;

        return solve(i);

    }
};

int main()
{
    string str = "ababbbabbababa";

    Solution S;

    cout << "Minimum Partitions : " << S.palindromicPartition(str) << endl;
}