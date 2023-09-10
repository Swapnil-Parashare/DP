#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public :

    // Note : Wording is very important in this question. It may cause a lot of confusion. Read Carefully !!!

    /***************************************************************      Visualizer    **********************************************************************/

                                    /*               -------------------------------------------------------------------------------------                   */
    vector<int> BestCase;           /*  It will hold | "Minimum Number of Attempts" required to determine Critical Floor in "Best Case"  |, at each floor.   */  
                                    /*               -------------------------------------------------------------------------------------                   */
    

                                    /*               -------------------------------------------------------------------------------------                   */
    vector<int> WorstCase;          /*  It will hold | "Minimum Number of Attempts" required to determine Critical Floor in "Worst Case" |, at each floor.   */   // IMP  : We will choose Best (i.e Minimum) from all these Worst Cases.
                                    /*               -------------------------------------------------------------------------------------                   */   // Note : 1] Assume at a particular floor 'x' attempts is stored.
                                                                                                                                                                  //        2] So 'x' are the "Minimum Number of Attempts" required to determine Critical floor in "Worst Case".          (At this floor)
    /*********************************************************************************************************************************************************/   //        3] In simple words, 'x' attempts are enough to determine Critical Floor in Worst Case.                        (At this floor)
                                                                                                                                                                  //        4] If we didn't used our attempts wisely, we will end up requiring more number of attempts in "Worst Case".   (At this floor)
    int eggs;                                                                                                                                                     //        5] But the bare minimum requirement is of "x" attempts only.                                                  (At this floor)
    int floors;
    vector<vector<int>> dp1;
    vector<vector<int>> dp2;


    
    int eggDrop1(int e, int f) 
    {
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        // Memoization
        if(dp1[e][f] != -1) return dp1[e][f];


        int temp_ans;
        int final_ans = INT_MAX;

        for(int k = 1 ; k <= f ; k++)                                  // Traversing all the floors.
        {


            temp_ans = 1 + max(                                        // Maximum is taken, because we are considering worst case.   (Certainity ----> Worst Case)
                            eggDrop1(e-1,k-1),                         // Break
                            eggDrop1(e, f-k)                           // Not Break
                         ); 


            /********** Visualizer ************/
            if(e == eggs && f == floors)
            {
                WorstCase[k] = temp_ans;                              // Answer for current floor is stored.
            }
            /**********************************/

            final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts from all the "Worst Cases". (BEST from the WORST)
        };

        return dp1[e][f] = final_ans;
    }

    int eggDrop2(int e, int f) 
    {
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        // Memoization
        if(dp2[e][f] != -1) return dp2[e][f];


        int temp_ans;
        int final_ans = INT_MAX;

        for(int k = 1 ; k <= f ; k++)
        {

            temp_ans = 1 + min(                                        // Minimum is taken, because we are considering  Best Case.
                            eggDrop2(e-1,k-1),                         // Break
                            eggDrop2(e, f-k)                           // Not Break
                         ); 


            /********** Visualizer ************/
            if(e == eggs && f == floors)
            {
                BestCase[k] = temp_ans;
            }
            /**********************************/

            final_ans = min(final_ans, temp_ans);                      // Choosing the Minimum from all the Best Cases. (BEST from the BEST)
        };

        return dp2[e][f] = final_ans;
    }

    void display(int ans)
    {

        int target;

        cout << "\nAnswer : " << ans << "\n" << endl;
        cout << endl;

        cout << "Floors         Best Case     Worst Case" << endl;
        cout << "---------------------------------------" << endl;

        for(int i = floors ; i >=1 ; i--)
        {
            if(WorstCase[i] == ans) target = i;

            if( i > 99)
            {
                cout << i   << "      :        " << BestCase[i]  << "             " << WorstCase[i] << endl;
            }
            else if(i > 9)
            {
                cout << i   << "       :        " << BestCase[i]  << "             " << WorstCase[i] << endl;
            } 
            else
            {
                cout << i   << "        :        " << BestCase[i]  << "             " << WorstCase[i] << endl;
            }
        }

        cout << "\n\n         Target Floor : " << target << endl;

        cout << "\n" << "+++++++++++++++++++++++++++++++++++++++" << endl;


    }

};


int main()
{

    
    int floors;
    int eggs;

    cout << "\nFloors : " ;
    cin >> floors;
    cout << "Eggs : ";
    cin >> eggs;

    Solution S;

    S.floors = floors;
    S.eggs = eggs;

    S.BestCase.resize(floors+1);                                       // Just for visualizing
    S.WorstCase.resize(floors+1);                                      // Just for visualizing
    
    S.dp1.resize(eggs+1,vector<int>(floors+1, -1));                   // Memoization
    S.dp2.resize(eggs+1,vector<int>(floors+1, -1));                   // Memoization
    
    int ans = S.eggDrop1(eggs,floors);                        
    
    S.eggDrop2(eggs,floors);                                          // Just to fill the "Best Case" vector. (This is "Best from the Best". Our correct ans is "Best from the Worst".)
    S.display(ans);  
}






/*
1] Our "Visualizer" code won't display correct output(table) for f = 1 , f = 0 & e = 1 though correct 'Answer' is displayed.
2] This is because, f = 1 , f = 0 & e = 1 are the base conditions.
3] Hence the functions never runs, it terminates at the very start by returning the correct output.
4] Thus our "BestCase" & "WorstCase" array remains empty, there are never modified.
5] This is why 0 , 0 is seen in the output.
*/