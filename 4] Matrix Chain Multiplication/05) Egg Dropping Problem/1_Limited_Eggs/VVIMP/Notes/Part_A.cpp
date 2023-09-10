
// Disclaimer : This is MCM pattern question. If you haven't done MCM yet, don't read further. Do it. Then come here.

/******************************************************************************************************************************************************

When Floors = 100, Eggs = 2, we know that bare minimum attempts required to determine critical floor with certainity are 14 (Code says so).
But can you atleast tell from which floor you should make your 1st Attempt to get this answer. Or even worse, can you mention step by step from 
which 14 floors are you gonna make your 14 attempts, so that you would determine the critical floor................... 
Can you?
Have you really understood this puzzle?
Think over it.

(Merely convincing yourself that, 
 1.Maximum is taken because we want Certainty. 
 2.When Certainity is expected we go for Worst Case.
 Won't help!!!
Please understand, just repeating the stuff which you have heard from youtube tutorials or read from GFG, Leetcode or other articles without truly 
understanding it, does no good to you.)

Solution :-           
                                                               PART A                                

Logic :-

============================================================= OVERVIEW ================================================================================

1] We will calculate bare minimum attempts required to determine critical floor, when we starting dropping egg from each floor, seprately.
   Means        If 1st Attempt is done from 1st floor ===> "X" is the answer.
                   1st Attempt is done from 2nd floor ===> "Y" is the answer.
                   1st Attempt is done from 3rd floor ===> "Z" is the answer.
                   Up untill 100 Floors.

2] Now, once we have answer for each floor, we will simply choose Minimum among them. This will be our Final Answer.  { final_ans = min(X,Y,Z.....) }

===========================================================  Section 1 ==================================================================================

Question is, how will you calcuate answer for a particular floor?

1] Lets says there are 'f' floors & 'e' eggs. You are currently at 'k'th floor. You decide to drop your egg from here.
2] Now there are only two possiblities. Either egg will break or it will survive.
3] Irrespective of the result (Break or Survive), we need to count our current attempt. Because you have took your shot & dropped the egg from 'k'th floor. An attempt is made.
4] Now, 


        Case I - BREAK
        1)If our egg breaks at 'k'th floor, it will obviously break at all the floors above it.
        2)So we just have to check all the floors below k.
        3)As our egg is broken. Hence our egg count is reduced by 1.
        4)Thus our problem is reduced to :- Floors = k-1 & Eggs = e-1.

        Case II - SURVIVE
        1)If our egg survives at 'k'th floors, it will obviously survive at the floors below it.
        2)So we just have to check all the floors above k.
        3)As our egg has survived, our egg count remains the same.
        4)Thus our problem is reduced to :- Floors = f-k & Eggs = e.

                          (Main Problem)
                          ==============
                            solve(f,e)               At 'k'th Floor                       
                               /\
                              /  \
                       Break /    \ Survive
                            /      \
                           /        \
             solve(k-1,e-1)          solve(f-k,e)                             
            ===============          =============
            (Subproblem 1)           (Subproblem 2)
        
        
        Remember what does solve(f,e) at particular k represents ?
        It will give Bare Minimum attempts required to determine Critical Floor when Egg is dropped from 'k'th floor.
        What does solve(f,e) represents?
        It will give Bare Minimum attempts required for given Floors & Eggs.     (Here, we simply choose minimum from each 'k')

        So now trust your subproblems, solve(k-1,e-1) & solve(f-k,e).
        They will give correct output for given Floors & Eggs.                   (Provided that accurate Base Conditions are written. We will come back to it later.)
        Don't try to go down recursively. Just think about this 1st Level.

        How are you gonna convert Answers returned by this subproblems into answer of your Main problem?
        
        1] We want certainity, Right? What does it really means?

        2] Lets says,
                1)For solve(f,e) we are giving output as 'x' attempts.
                2)Then 'x' attempts should be enough for determining Critical Floor. PERIOD......
                3)It doesn't matter how wrong the thing goes, 'x' attempts should still be enough. Thats it.

        3] Now when we drop an egg, whether it will break or survive is not in our hand. Its the matter of pure luck.

        4] For understanding, lets say Subproblem 1 (Break) gives 21 as output & Subproblem 2 (Survive) gives 30 as ouput.


                            solve(f,e)               At 'k'th Floor                       
                               /\
                              /  \
                       Break /    \ Survive
                            /      \
                           /        \
             solve(k-1,e-1)          solve(f-k,e)     
                    ||                    ||
                    \/                    \/  
                    21                    30

        5] Thou, the breaking or survial of the egg is not in our control, but we can prepare for the WORST.
        6] By doing so, we can remain assured that, no matter what happens, how wrong thing goes, we would still determine critical floor successfully.
        7] This is the reason we select the subproblem which gives larger output.
        8] Inorder to do so, we are using the 'max()' function.
        9] Don't forget to count our "Current Attempt", which we have discussed earlier.

                                            solve(f,e)               At 'k'th Floor                       
                                              /\
                                             /  \
                                      Break /    \ Survive
                                           /      \
                                          /        \
            1   +   max{    solve(k-1,e-1)    ,     solve(f-k,e)   }
                                ||                       ||
                                \/                       \/  
                                21                       30

        10] Thus the OUTPUT is 31.
        11] Now lets say we dropped our egg from 'k'th floor & we are lucky, so the egg didn't break.
            Then we would determine critical floor in 22 attempts only. (which is less than our output i.e 31)
            But what if we are not lucky enough & the egg survived. Now we will end up requiring 31 attempts to determine critical.
        12] No matter what happens, 31 attempts are enough to determine critical floor.


                             We are done with caluclating answer for a particular floor

==============================================================  Section 2 ==============================================================================

Now we know how to calculate the answer for particular floor. We we calculate the answer for all the floor & will simply choose minimum among them. (As we disscussed in our overview)

int solve(int f, int e)
{
    int temp_ans;                                        // It will hold the answer for each floor.
    int final_ans = INT_MAX;                        
    for(int k = 1 ; k <= f ; k++)
    {
        temp_ans = 1 + max( solve(k-1,e-1) , solve(f-k,e) );
        final_ans = min(temp_ans, final_ans);
    }
    return final_ans;
}

==============================================================  Section 3 ==============================================================================

Only thing remainig is the Base Condition.
It is very important in Recursion. 
It tell you when to terminate the Recursion, thus breaking the chain of continuous recursive calls.
Just terminating recurssive function is not enough, we should be able to terminate it by returning correct value.

In recursion we know that, we always make reucrssive calls on smaller input.
So, just think about "Smallest Valid Input" or "First Invalid Input".

Larger========================================> Smaller
Valid Valid Valid Vaild Invalid Invalid Invalid Invalid
                    ||     ||
                    \/     \/
            Just think about these two.

1] Lets say our eggs are reduced to 1.

   Now we have to determine Critical Floor using single egg only.
   We cannot risk dropping it from upper floor. Because if it breaks then Critical Floor would remain undetermined.
   Best Stratergy is to start dropping eggs from 1st floor to up until top floor is reached.

   Case I   - If egg breaks at 1st floor itself. Then 0th floor is Critical floor.
   Case II  - If egg breaks anywhere in between, then the floor which is just below the floor where our egg broke, is our Critical Floor.
   Case III - If egg the survived even the top floor. Then top floor itself is our Critical Floor.

   Now we have to consider the worst case.
   CASE III is were we would end up requiring largest number of attempts, which will be equal to total no of floors.

   Therefore    if(e == 1) return f;


2] Lets say our floors are reduced to 1.

   Then we would need to perform atleast 1 attempt.
   If egg survived, then the 1st floor itself is the critical floor.
   If egg breaks, then the 0th floor is our critical floor.

   Therefore    if(f == 1) return 1;

3] Lets says our floors are reduced to 0.

    +------------------------------------------------------------------------------------+
    |   Now keep in mind, our eggs will never become 0.                                  |                                              
    |   Why? Observe below diagram.                                                      |                        
    |                                                                                    |                                    
    |                       solve(f,e)               At 'k'th Floor                      |                                                                                      
    |                          /\                                                        |                                                                    
    |                         /  \                                                       |                                                            
    |                  Break /    \ Survive                                              |                                                    
    |                       /      \                                                     |                                
    |                      /        \                                                    |                                                
    |        solve(k-1,e-1)          solve(f-k,e)                                        |                                        
    |                                                                                    |                                        
    |   We are reducing our eggs, at max by 1.                                           |                                                                                    
    |   Eggs :  5-->4-->3-->2-->1 BASE CONDITION HITS !!!                                |                                        
    |   As soon as egg becomes 1, our base condition hits and 'f' is returned as answer. |    
    +------------------------------------------------------------------------------------+

    This is not the case with Floors.
    There are only 2 Cases were our Floors would become 0.

    1] Egg Breaks on 1st floor itself.
    2] Egg Survives on even Even Top Floor.

    Now, in both the above cases, our Critical Floor is already determined.
    If Egg breaks on 1st floor, then 0th Floor is our Critical Floor.
    If Egg survives on top floor, then top floor itself is our Critical Floor.

    Note :- We have already counted our current attempt, while dropping the egg from top or 1st floor respectively.

    So now, no more attempts are required to determine the critical floor.

    Therefore  if(f == 0) return 0;

==============================================================  Final Recurssive Code ==============================================================================

int solve(int f, int e)
{
    if(e == 1 || f == 0 || f == 1)
    {
        return f;
    }

    int temp_ans;                                      
    int final_ans = INT_MAX;                        
    for(int k = 1 ; k <= f ; k++)
    {
        temp_ans = 1 + max( solve(k-1,e-1) , solve(f-k,e) );
        final_ans = min(temp_ans, final_ans);
    }
    return final_ans;
}

220 Lines of explanation for 16 Lines of code. :) 
========================================================================X============================================================================================*/






