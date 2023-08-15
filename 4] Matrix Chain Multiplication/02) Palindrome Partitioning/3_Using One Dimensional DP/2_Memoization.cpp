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
        // Base Condition.
        if(i == N-1) return 0;

        // Memoization
        if(dp[i] != -1) return dp[i];

        if(isPalindrome(i,N-1)) return dp[i] = 0;

        int final_ans = INT_MAX;
        int temp_ans;

        for(int k = i ; k < N-1 ; k++)            // Partitioning.
        {
            if(isPalindrome(i,k))
            {
                temp_ans = 1 + solve(k+1);
                final_ans = min(temp_ans,final_ans);
            }
        }
        return dp[i] = final_ans;
    }

    int palindromicPartition(string str)
    {
        this->str = str;
        this->N = str.size();

        dp.resize(N,-1);
        int i = 0;

        return solve(i);

    }
};

int main()
{
    string str = "aaabba";

    Solution S;

    cout << "Minimum Partitions : " << S.palindromicPartition(str) << endl;
}