#include<iostream>

using namespace std;

class Solution
{
    public:

    int solve(int e, int f)
    {
        // Base Condition
        if(e == 1 || f == 0 || f == 1)
        {
            return f;
        }

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