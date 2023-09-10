#include<iostream>
#include<cmath>

using namespace std;

class Solution
{
    public:

    // This calculates log to the base 2, in constant time. (Bit Manipulation)
    int log(long long x)                                                               // 1. This function breaks on my VS Code, but works perfectly on leetcode.
    {                                                                                  // 2. For f = 100, e = 100     VS Code Output = 39.  Expected Output = 7.
        return 64 - __builtin_clzl(x) - 1;                                             // 3. When same input is given on Leetcode Custom Testcase,  Output = 7.
    }                                                                                  // 4. This is because maybe it is complier specific. (GCC)
                                                                                       // 5. Instead of using this function, simply use " log2() " inbuilt function. Correct output is achieved.
    
    int solve(int e, int f)
    {
        // Base Condition
        if(e == 1 || f == 0 || f == 1)
        {
            return f;
        }

        // If Sufficient amount of eggs are present.
        int sufficient = log2(f) + 1;
        if(e >= sufficient) return sufficient;


        int temp_ans;
        int final_ans = INT_MAX;

        // Variables needed for Binary Search.
        int low = 1;                                        // This is our current
        int high = f;                                       //  MAIN PROBLEM

        int mid;

        int Break;
        int Survive;

        while(low <= high)
        {
            mid = (low+high)/2;

            Break = solve(e-1,mid-1);
            Survive = solve(e,f-mid);                            // IMP : We are working on our "Main Problem". Main Problem -> "f". Hence do 'f-mid', not 'high-mid'.            

            temp_ans = 1 + max(Break,Survive);
            final_ans = min(temp_ans,final_ans);

            /*******************/
            if(Break > Survive)                                // Just modifying "low" & "high", so that our while loop functions correctly.
            {                                                  // Shift towards the section whose output is "Maximum".
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
            /*******************/
        }

        return final_ans;
    }

    int eggDrops(int e, int f)
    {
        return solve(e,f);
    }
};

int main()
{
    int Floors, Eggs;
    cout << "Floors : ";
    cin >> Floors;
    cout << "Eggs : ";
    cin >> Eggs;

    Solution S;

    cout << "Answer : " << S.eggDrops(Eggs,Floors) << endl;
}