#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public :

    // Note : Wording is very important in this question. It may cause a lot of confusion. Read Carefully !!!

    /***************************************************************      Visualizer    **********************************************************************/

                                    /*               -------------------------------------------------------------------------------------                   */
    vector<int> WorstCase;          /*  It will hold | "Minimum Number of Attempts" required to determine Critical Floor in "Worst Case" |, at each floor.   */   // IMP  : We will choose Best (i.e Minimum) from all these Worst Cases.
                                    /*               -------------------------------------------------------------------------------------                   */   // Note : 1] Assume at a particular floor 'x' attempts is stored.
                                                                                                                                                                  //        2] So 'x' are the "Minimum Number of Attempts" required to determine Critical floor in "Worst Case".          (At this floor)
    /*********************************************************************************************************************************************************/   //        3] In simple words, 'x' attempts are enough to determine Critical Floor in Worst Case.                        (At this floor)
                                                                                                                                                                  //        4] If we didn't used our attempts wisely, we will end up requiring more number of attempts in "Worst Case".   (At this floor)
    int floors;
    vector<int> dp;

    int eggDrop1(int f) 
    {
        // Base Condition
        if(f == 1 || f == 0) return f;

        // Memoization
        if(dp[f] != -1) return dp[f];


        int temp_ans;
        int final_ans = INT_MAX;

        for(int k = 1 ; k <= f ; k++)                                  // Traversing all the floors.
        {


            temp_ans = 1 + max(                                        // Maximum is taken, because we are considering worst case.   (Certainity ----> Worst Case)
                            eggDrop1(k-1),                             // Break
                            eggDrop1(f-k)                              // Not Break
                         ); 


            /********** Visualizer ************/
            if(f == floors)
            {
                WorstCase[k] = temp_ans;                              // Answer for current floor is stored.
            }
            /**********************************/

            final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts from all the "Worst Cases". (BEST from the WORST)
        };

        return dp[f] = final_ans;
    }

    
    void display(int ans)
    {

        int target;

        cout << "\nAnswer : " << ans << "\n" << endl;
        cout << endl;

        cout << "Floors       Worst Case" << endl;
        cout << "-----------------------" << endl;

        for(int i = floors ; i >=1 ; i--)
        {
            if(WorstCase[i] == ans) target = i;

            if( i > 99)
            {
                cout << i   << "      :        "  << WorstCase[i] << endl;
            }
            else if(i > 9)
            {
                cout << i   << "       :        "  << WorstCase[i] << endl;
            } 
            else
            {
                cout << i   << "        :        " << WorstCase[i] << endl;
            }
        }

        cout << "\n\n         Target Floor : " << target << endl;

        cout << "\n" << "+++++++++++++++++++++++++++++++++++++++" << endl;


    }

};


int main()
{

    
    int floors;

    cout << "\nFloors : " ;
    cin >> floors;

    Solution S;

    S.floors = floors;

    S.WorstCase.resize(floors+1);                                      // Just for visualizing
    
    S.dp.resize(floors+1,-1);                                          // Memoization
    
    int ans = S.eggDrop1(floors);                        
    
    S.display(ans);  
}





