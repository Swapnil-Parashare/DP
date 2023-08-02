#include<iostream>

using namespace std;

class Solution
{
    public :

    int lcs(string s1, string s2, int m, int n)
    {
        // Base Condition
        if( m==0 || n==0 )
        {
            return 0;
        }

        // Choice Diagram
        if(s1[m-1] == s2[n-1])
        {
            return 1 + lcs(s1,s2,m-1,n-1);
        }
        else
        {
            return max(lcs(s1,s2,m,n-1), lcs(s1,s2,m-1,n));
        }
    }
};

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    int m = s1.size();
    int n = s2.size();

    Solution S1;

    cout << S1.lcs(s1,s2,m,n) << endl;
}