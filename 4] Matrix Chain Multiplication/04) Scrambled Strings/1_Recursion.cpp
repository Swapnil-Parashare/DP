#include<iostream>

using namespace std;

class Solution{
    public:


    bool solve(string a , string b)
    {
        int n = a.size();

        // Base Condition

        if(n == 1)
        {
            return a == b;                                          // Its going to hit for sure !!!
        }

        if( a == b)                                                // Just to avoid unneccessary computation.                
        {
            return true;
        }


        bool flag = false;

        for(int i = 1 ; i < n ; i++)
        {
            if(     ( solve(a.substr(0,i), b.substr(n-i,i) )    &&    solve(a.substr(i,n-i), b.substr(0,n-i)) )             // Swap
                                                                ||
                    ( solve(a.substr(0,i), b.substr(0,i))       &&    solve(a.substr(i,n-1), b.substr(i,n-i)) )             // No Swap
              )
            {
                flag = true;
                break;
            }
            
        }
        return flag;
    }

    bool isScramble(string S1, string S2)
    {
        return solve(S1,S2);
    }    
};

int main()
{
    string s1 = "great";
    string s2 = "tearg";

    Solution S;

    cout << "Answer : " << S.isScramble(s1,s2) << endl;
}