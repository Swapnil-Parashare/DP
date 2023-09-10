#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution
{
    public :

    int floors;
    int eggs;
    vector<vector<int>> dp;

    vector<int> midAnswers;
    vector<int> sequence;
    vector<int> eggBreak;
    vector<int> eggSurvive;
    vector<string> decision;

    
    int solve(int e, int f) 
    {
        // Base Condition
        if(e == 1 || f == 1 || f == 0)
        {
            return f;
        }

        // Memoization
        if(dp[e][f] != -1) return dp[e][f];


        int temp_ans;
        int final_ans = INT_MAX;


        // Binary Search Approach.
        int l = 1;
        int h = f;
        int mid;
        int Break;
        int Survive;

        // for(int k = 1 ; k <= f ; k++)       // He is checking only middle floor.
        
        int break_flag = false;
        while(l <= h)
        {
            mid = (l+h)/2;

            Break = solve(e-1,mid-1);         // Lower Part
            Survive = solve(e, f-mid);        // Upper Part
            temp_ans = 1 + max(Break, Survive); 

            

            if(Break > Survive)
            {
                break_flag = true;
            }
            else
            {
                break_flag = false;
            }
                

            /************ Visualizer ************/
            if(e == eggs && f == floors)                               // This condition is very important. I am only concerned about my "Main Problem" and not with Subproblems which will be created.
            {
                midAnswers[mid] = temp_ans;                            //  ||INDEX = Floor Number||  :  Answer at that floor.
                sequence.push_back(mid);                               // To know the sequence of floors in which answers are computed.
                
                eggBreak[mid] = Break;
                eggSurvive[mid] = Survive;

                if(break_flag)                                         // To know what was the Worst Case. (Break or Survive)
                {
                    decision[mid] = "BREAK  ";
                }
                else
                {
                    decision[mid] = "SURVIVE";                         // If egg survives at 'mid' Index, then this is the output.
                }

            }
            /***********************************/

            // Shift to subproblem which gives maximum input.
            if(Survive > Break)     
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }


            final_ans = min(final_ans,temp_ans);                      // Minimum Number of attempts in all the "Worst Cases".
        }

        return dp[e][f] = final_ans;
    }

    int eggDrop(int e, int f) 
    {
        dp.resize(e+1,vector<int>(f+1, -1));
        midAnswers.resize(f+1,-1);
        eggBreak.resize(f+1,-1);
        eggSurvive.resize(f+1,-1);

        decision.resize(f+1);


        return solve(e,f);
    }

    void display(int ans)
    {
        
        cout << "\nAttempts : " << ans << endl;

        cout << "\nFloors         Worst Case" << endl;
        cout << "-------------------------" << endl;

        for(int i = floors ; i > 0 ; i--)
        {   
            if(midAnswers[i] != -1)                                                // Only Display the floors whose computation are done.
            {
                if( i > 99)
                {
                    cout << i   << "      :        " <<  midAnswers[i] << endl;
                }
                else if(i > 9)
                {
                    cout << i   << "       :        " <<   midAnswers[i] << endl;
                } 
                else
                {
                    cout << i   << "        :        " <<   midAnswers[i] << endl;
                }
            }
        }

        cout << "\nAs you can see the answers of only specific floors are computed !!!" << endl;
        cout << "Sequence in which answers are computed. \n" << endl;
        int start = 1;

        cout << "\nSequence        Floor No           Break           Survive          Worst Case            Output" << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        for(int element : sequence)
        {    
            if(start > 9)
            {

                cout << start   << "        :        " <<  element <<  "      :        "<< eggBreak[element] <<"      :        " << eggSurvive[element]<< "      :        "<< decision[element] <<"      :        " << midAnswers[element] << endl;
            }
            else
            {
                cout << start   << "         :        " <<  element <<  "      :        "<< eggBreak[element] <<"      :        " << eggSurvive[element]<< "      :        "<< decision[element] <<"      :        " << midAnswers[element] << endl;

            }
            start++;
        }
        cout << endl;
    }
    
};


int main()
{
    while(true)
    {

    
    int eggs;
    int floors;
    cout << "Floors : ";
    cin >> floors;
    cout << "Eggs : ";
    cin >> eggs;

    Solution S;
    S.eggs = eggs;
    S.floors = floors;

    
    int ans = S.eggDrop(eggs,floors);
     S.display(ans);

    }
}

/*
Note : 1] It may look like the 'last floor' which we are checking always has the Minimum Output.
       2] But thats not the case.
       3] Check for Floors : 123 , Eggs : 3 & see it for yourself.
*/
    