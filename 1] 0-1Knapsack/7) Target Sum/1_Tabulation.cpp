#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
  public:
    
    vector<vector<int>> dp;
    const long long int limit = 1e9 + 7;


    // Count Subset Problem
    int countSubset(vector<int>& arr, int n, int sum)
    {
        //Initialization
        for(int j = 0 ; j <= sum ; j++) dp[0][j] = 0;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
        
        //Choice Diagram
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= sum ; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % limit;
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }


  
    int findTargetSumWays(vector<int>&arr ,int d) 
    {
        
        int n = arr.size();

        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        
        // Both 'sum' & 'difference' both, should either be even or odd, only then partition is possible.
        if((sum+d) % 2 != 0) return 0;
        
        
        // This is the sum whose count we have  to find out.
        int target = (sum + d)/2;
        
        
         // Handling the presence of ZERO's.          
         
         int zeroCount = 0;
         vector<int> vec;
         
         for(int i = 0 ; i < n ; i++ )
         {
             if(arr[i] != 0) 
             {
                 vec.push_back(arr[i]);
             }
             else
             {
                 zeroCount++;
             }
         }
         
        int newSize = vec.size();
        
        dp.resize(newSize + 1,vector<int>(target + 1));
        
        
        int ansWithoutZero = countSubset(vec,newSize,target);
        
        long long int final = (ansWithoutZero * pow(2,zeroCount));      
        
        return final % limit;
        
        
    }
};

int main()
{
    vector<int> arr = {1,1,1,1,1};
    int d = 3;

    Solution S1;

    cout << S1.findTargetSumWays(arr,d) << endl;
}