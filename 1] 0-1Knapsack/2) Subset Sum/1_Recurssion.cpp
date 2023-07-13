#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public : 

    bool subsetSum(vector<int>& arr, int n, int sum)
    {
        // Base Condition
        if(sum == 0) return true;
        if(n == 0) return false;

        // Choice Diagram
        if(arr[n-1] <= sum)
        {
           return  subsetSum(arr,n-1,sum - arr[n-1]) || subsetSum(arr,n-1,sum);
        }
        else
        {
            return subsetSum(arr,n-1,sum);
        }
    }
};

int main()
{
    vector<int> arr = {2,3,5,8,11};
    int sum = 11;
    int n = arr.size();

    Solution S1;

    cout << S1.subsetSum(arr,n,sum) << endl;
}