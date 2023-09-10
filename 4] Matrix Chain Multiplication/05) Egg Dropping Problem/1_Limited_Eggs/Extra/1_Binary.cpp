#include <iostream>

using namespace std;

class Solution
{
    public :


    /*  Use this code to verify it for yourself that "Why Binary Search approach won't work for Egg Drop Problem ?"  */
    
    int eggDrop1(int e, int f) 
    {
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        int temp_ans;
        int check = (f+1)/2;  

        temp_ans = 1 + max(                                            // Maximum is taken, because we are considering Worst Case.  (Here we have Certainity)
                        eggDrop1(e-1,check-1),                         // Break
                        eggDrop1(e, f-check)                           // Not Break
                     ); 
        return temp_ans ;
    }

    int eggDrop2(int e, int f) 
    {
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        int temp_ans;
        int check = f/2;  

        temp_ans = 1 + min(                                            // Minimum is taken, because we are considering Best Case.  (Here we don't have Certainity.)
                        eggDrop2(e-1,check-1),                         // Break
                        eggDrop2(e, f-check)                           // Not Break
                     ); 
        return temp_ans ;
    }

};


int main()
{
    int eggs = 2;
    int floors = 100;

    cout << "\nFloors : " << floors << endl;
    cout << "Eggs   : " << eggs << endl;

    Solution S;

    int Worst_Case = S.eggDrop1(eggs,floors);
    int Best_Case = S.eggDrop2(eggs,floors);

    cout << "\nWe always have to choose \"Worst Case\", because we want \"Certainity\"." << endl;

    cout << "\nBest Case Attempts  : " << Best_Case << endl;
    cout << "Worst Case Attempts : " << Worst_Case << endl;
    cout << endl;
}

/* Floors = 100, Eggs = 2
1] In Binary search approach you will end up using 50 attempts in worst case to determine Critical Floor.   (Each attempt is done from center, until single egg is left)
2] While by our MCM approach you can determine Critical Floor in just 14 Attempts in Worst Case.            (1st Attempt will be made from 9th floor onwards.)
*/