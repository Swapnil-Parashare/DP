#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution
{
    public : 

    // Subset Sum Function
    bool solve(vector<int>& arr, int n, int sum)
    {
        // Base Condition
        if(sum == 0 ) return true;
        if(n == 0) return false;

        // Choice Diagram
        if(arr[n-1] <= sum)
        {
            return solve(arr,n-1,sum-arr[n-1]) || solve(arr,n-1,sum);
        }
        else
        {
            return solve(arr,n-1,sum);
        }


    }

    bool equalPartition(vector<int> arr, int n)
    {
        int sum = accumulate(arr.begin(), arr.end(),0);
        
        if(sum%2 != 0) return false;

        sum /= 2;

        return solve(arr,n,sum);
    }
};

int main()
{
    vector<int> arr = {1,5,11,5};
    Solution S1;

    cout << S1.equalPartition(arr, arr.size()) << endl;
}
