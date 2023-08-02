#include<iostream>

using namespace std;

class Solution
{
    public : 

    string s1;
    string s2;

    int solve(int m, int n, int count)
    {
        // Base Condition
        if(m == 0 || n == 0)
        {
            return count;                            // Return whatever is the count till now.
        }

        // Choice Diagram
        
        if(s1[m-1] == s2[n-1])
        {
            return max( solve(m-1,n-1,count + 1), max(solve(m-1,n,0), solve(m,n-1,0)));
        }
        else
        {
            return max(count, max(solve(m-1,n,0), solve(m,n-1,0)));
        }   
    }

   
    int substring(string s1, string s2, int m, int n)
    {
        // Just making strings accessible to any "Member Function". Just like Global.
        this->s1 = s1;     
        this->s2 = s2;

        return solve(m,n,0);
    }


};

int main()
{
    string s1 = "abc";
    string s2 = "cab";

    Solution S;

    cout << S.substring(s1,s2,s1.size(), s2.size()) << endl;

}