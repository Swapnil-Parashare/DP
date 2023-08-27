#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


                                    /*   Memoization using 3 Unordered Map   */

                                   /* Note : Time taken by 3D Matrix Code     : 0.03 ms     (Preferred)
                                             Time taken by Unordered Map Code : 0.39 ms                          */


class Solution
{
    public:

    string str;
    int N;
    unordered_map<string, int> mp;

    int solve(int i, int j, int target)
    {
        // Base Condition
        if(i == j)
        {
            if( (target == 1  && str[i] == 'T' )  || (target == 0 && str[i] == 'F'))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // Memoization
        string key = to_string(i) + to_string(j) + to_string(target);
        if(mp.find(key) != mp.end()) return mp[key];


        char op;
        int lt,lf,rt,rf;
        int temp_ans;
        int final_ans = 0;

        for(int k = i+1; k < j ; k+=2)
        {
            lt = solve(i,k-1,1);
            lf = solve(i,k-1,0);
            rt = solve(k+1,j,1);
            rf = solve(k+1,j,0);

            op = str[k];

            switch (op)
            {
                case '&' :
                {   
                    if(target == 1)
                    {
                        temp_ans = lt * rt;
                    }
                    else
                    {
                        temp_ans = (lt * rf) + (lf * rt) + (lf * rf);
                    }
                    break;
                }


                case '|' :
                {
                    if(target == 1)
                    {
                        temp_ans = (lt * rf) + (lf * rt) + (lt * rt);
                    }
                    else
                    {
                        temp_ans = lf * rf;
                    }
                    break;
                }


                case '^' :
                {
                    if(target == 1)
                    {
                        temp_ans = (lt * rf) + (lf * rt);
                    }
                    else
                    {
                        temp_ans = (lt * rt) + (lf * rf);
                    }
                    break;
                }
                
                default:
                    break;
            }

            final_ans += temp_ans;
        }

        return mp[key] = (final_ans % 1003);
    }

    int countWays(int N, string S)
    {
        this->str = S;
        this->N = N;

        return solve(0,N-1,1);
    }
};

int main()
{
    string str = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    int N = str.size();

    Solution S;

    int ans = S.countWays(N,str) ;

    cout << "Answer :  " << ans << endl;   
}

/* First working code after 2 weeks of gap :) */