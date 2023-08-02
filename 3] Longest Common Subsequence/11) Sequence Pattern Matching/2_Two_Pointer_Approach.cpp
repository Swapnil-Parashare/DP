#include<iostream>

using namespace std;

class Solution
{
    public :

    string s1;          // Longer
    string s2;          // Shorter

    bool solve()
    {
        int m = s1.size();
        int n = s2.size();

        int j = 0;
        for(int i = 0 ; i < m ; i++)
        {
            if(s2[j] == s1[i])
            { 
                j++;
            }
        }

        return j == n;
    }

    bool isSubSequence(string A, string B)                   // Wheather 'B' is present as a subsequence in 'A' OR Viceversa
    {

        // Pass Longer String as S1 & Shorter String as S2.  
        if(A.size() > B.size())
        {
            this->s1 = A;
            this->s2 = B;
        } 
        else
        {
            this->s1 = B;
            this->s2 = A;
        }

        return solve();

    }

};

int main()
{

    string A = "ADXCPY";
    string B = "AXY";

    Solution S;

    cout << S.isSubSequence(A,B) << endl;


}