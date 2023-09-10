#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
    public :

    
    int eggDrop(int f) 
    {
        // Base Condition
        if(f == 1 || f == 0) return f;

        int mid = (f+1)/2;

        int ans = 1 + max(eggDrop(mid-1),eggDrop(f-mid) );          

        return ans;

    }
};


int main()
{
    while(true)
    {
        
        int floors;
        cout << "Floors : ";
        cin >> floors;


        Solution S;

        cout << "\nAnswer By Code : " << S.eggDrop(floors) << endl;

        cout << "\nAnswer By Log  : " << floor( log2(floors) + 1 ) << endl;

        cout << endl;
    }

}

/*
1] Even with Infinite Egg Supply,
2] If we check just middle floor,
3] Still we are not getting correct output.

Floors = 10         Expected Output = 4
                    Our Output      = 5
*/


