#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public :

    int coinChange(vector<int>& coins, int n, int sum)
    {
        // Base Condition
        if(sum == 0) return 1;
        if(n == 0) return 0;

        // Choice Diagram
        if(coins[n-1] <= sum)
        {
            return coinChange(coins,n,sum-coins[n-1])                              // Include (Not Processed)
                                +
                   coinChange(coins,n-1,sum);                                      // Not Include (Processed) 
        }
        else
        {
            return coinChange(coins,n-1,sum);                                       // Not Include (Processed)
        }
    }
};

int main()
{
    vector<int> coins = {1,2,3};
    int sum = 5;

    Solution S1;

    cout << S1.coinChange(coins,coins.size(),sum) << endl;
}

/* Same as "Count Subset Sum" Problem. Only difference is infinite supply of elements. i.e (Unbounded Knapsack)*/