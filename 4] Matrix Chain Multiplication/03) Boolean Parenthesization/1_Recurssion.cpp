#include<iostream>

using namespace std;

class Solution
{
    public:

    string str;
    int N;

    int solve(int i, int j, bool target)
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

        char op;
        int lt,lf,rt,rf;
        int temp_ans;
        int final_ans = 0;

        for(int k = i+1; k < j ; k+=2)
        {
            lt = solve(i,k-1,true);
            lf = solve(i,k-1,false);
            rt = solve(k+1,j,true);
            rf = solve(k+1,j,false);

            op = str[k];

            switch (op)
            {
                case '&' :
                {   
                    if(target == true)
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
                    if(target == true)
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
                    if(target == true)
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

        return final_ans;
    }

    int countWays(int N, string S)
    {
        this->str = S;
        this->N = N;
        return solve(0,N-1,true);
    }
};

int main()
{
    string str = "T|T&F^T";
    int N = str.size();

    Solution S;

    int ans = S.countWays(N,str) ;

    cout << "Answer :  " << ans << endl;   
}

/* First working code after 2 weeks of gap :) */