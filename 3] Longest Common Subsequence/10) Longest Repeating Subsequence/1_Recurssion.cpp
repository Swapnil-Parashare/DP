#include<iostream>

using namespace std;

class Solution
{
    public :

    string s1;
    string s2;

    int lrs(int m, int n)
    {
        // Base Condition
        if(m == 0 || n == 0) 
        {
            return 0;
        }

        // Choice Diagram
        if( (s1[m-1] == s2[n-1]) && (m!=n) )
        {
            return 1 + lrs(m-1,n-1);
        }
        else
        {
            return max( lrs(m,n-1) , lrs(m-1,n) );
        }
    }

	int LongestRepeatingSubsequence(string str)
    {
	    this->s1 = str;
        this->s2 = str;

        int m = str.size();
        int n = str.size();

        int ans = lrs(m,n);

        return ans;
	}

};


int main()
{
    string str = "AABEBCDD";
    
    Solution S;

    cout << S.LongestRepeatingSubsequence(str) << endl;
}