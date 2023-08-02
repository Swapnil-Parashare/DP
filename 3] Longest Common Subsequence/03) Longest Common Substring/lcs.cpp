#include<iostream>

using namespace std;

class Solution
{
    public : 

    string s1;
    string s2;

    /* Here we have solved LCS problem by using extra 'count' variable. 
       This is just to ensure that our thought process during Longest Common Substring's Recurssive approach is correct.*/
    
    int solve(int m, int n, int count)
    {
        // Base Condition
        if(m == 0 || n == 0) return count;

        // Choice Diagram
        if(s1[m-1] == s2[n-1])
        {
            return solve(m-1,n-1,count+1);
        }
        else
        {
            return max(solve(m,n-1,count),solve(m-1,n,count));
        }
    }

    int subSequence(string s1, string s2, int m, int n)
    {
        // Just making strings accessible to any "Member Function". Just like Global.
        this->s1 = s1;     
        this->s2 = s2;

        return solve(m,n,0);
    }


};

int main()
{
    string s1 = "ajcmxyz";
    string s2 = "jacnxyz";

    Solution S;

    cout << S.subSequence(s1,s2,s1.size(), s2.size()) << endl;

}