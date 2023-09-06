#include <iostream>

using namespace std;

class Solution
{
    public :

    
    int eggDrop(int e, int f) 
    {
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }


        int temp_ans;
        int final_ans = INT_MAX;

        for(int k = 1 ; k <= f ; k++)
        {
            temp_ans = 1 + max(                                       // Maximum is taken, because we are considering worst case.
                            eggDrop(e-1,k-1),                         // Break
                            eggDrop(e, f-k)                           // Not Break
                         ); 

            final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts in all the "Worst Cases". (Chossing Best from the Worst)
        };

        return final_ans;
    }
};


int main()
{
    int floors = 100;
    int eggs = 2;

    Solution S;

    // (Eggs, Floors)

    cout << "Attempts : " << S.eggDrop(eggs,floors) << endl;
}


// We want : "Gauranted" Minimum Number of attempts, to find first floor from the top were egg doesn't break.

/*  1] It means, at least you will need this many attempts to find the critical floor in the worst case.
    2] You will find the critical floor for sure in this many attempts, if used correctly.
    3] You can obviously find critical floor using more attempts than this. (If you don't use attempts wisely)
    4] But there is no way you will figure out what the critical floor is, using less attempts than this, in the worst case.
*/
