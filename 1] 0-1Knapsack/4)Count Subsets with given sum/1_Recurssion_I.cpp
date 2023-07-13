#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public :

	const long long int limit = 1e9+7;

    int solve(vector<int>& arr, int n, int sum)
    {
        // Base Condition
        if(sum == 0) return 1;
        if(n == 0) return 0;

        // Choice Diagram
        if(arr[n-1] <= sum)
        {
            return  (solve(arr,n-1,sum-arr[n-1]) +  solve(arr,n-1,sum)) % limit;
        }
        else
        {
            return solve(arr,n-1,sum);
        }
    }

    int perfectSum(vector<int>& arr, int n, int sum)
    {
        sort(arr.begin(),arr.end(), greater<int>());           // To tackle the presence of ZERO (Read Notes)
        return solve(arr,n,sum);
    }
};

int main()
{
    vector<int> arr = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};
    int n = arr.size();
    int sum = 31;

    Solution S1;

    cout << S1.perfectSum(arr,n,sum) << endl;
}