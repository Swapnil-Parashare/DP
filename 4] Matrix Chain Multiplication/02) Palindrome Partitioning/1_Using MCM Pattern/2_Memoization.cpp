#include<iostream>
#include<vector>

using namespace std;

class Solution
{

public:

    string str;
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
        // Base Condition
        if(i == j ) return 0;
        if(isPalindrome(i,j)) return 0;

        // Memoization
        if(dp[i][j] != -1) return dp[i][j];

        int final_ans = INT_MAX;
        int temp_ans;

        for(int k = i ; k < j ; k++)
        {
            temp_ans = solve(i,k) + solve(k+1,j) + 1;
            final_ans = min(temp_ans, final_ans);
        }

        return dp[i][j] = final_ans;
    }
    
    int palindromicPartition(string str)
    {
        this->str = str;

        int size = str.size();
        int i = 0;
        int j = size - 1;

        dp.resize(size,vector<int>(size,-1));

        return solve(i,j);
    }
};

int main()
{
    string str = "xxiiiwwyyy";

    Solution S;

    cout << "Minimum Partitions : " << S.palindromicPartition(str) << endl;
}