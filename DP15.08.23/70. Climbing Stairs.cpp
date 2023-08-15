/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

/*Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
Accepted
2.5M
*/
//recursive solution
class Solution {
public:

int climbStairsRec(int n)
{
   if(n==0)
   return 1;

   if(n==1)
   return 1;

   int o=climbStairsRec(n-1);
   int t=climbStairsRec(n-2);

   return o+t;
}
//memoisation solution
int climbStairsMemo(int n,vector<int>&dp)
{
   if(n==0)
   return 1;

   if(n==1)
   return 1;

if(dp[n]!=-1)
return dp[n];

   int o=climbStairsMemo(n-1,dp);
   int t=climbStairsMemo(n-2,dp);

   return dp[n]=o+t;
}
//tabulation solution
int climbStairsTab(int n)
{
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
   int o=dp[i-1];
   int t=dp[i-2];

    dp[i]=o+t;
    }
    return dp[n];
}

int climbStairsTabSO(int n)
{
    vector<int>dp(n+1,0);
    int prev1=1,prev2=1,curr=0;
  
   for(int i=2;i<=n;i++)
    {
   int o=prev1;
   int t=prev2;

    curr=prev1+prev2;
    prev2=prev1;
    prev1=curr;


    }
    return curr;
}

int climbStairs(int n) {
      vector<int>dp(n+1,-1);
    //    return climbStairsRec(n);
    //return climbStairsMemo(n,dp);
    return climbStairsTab(n);
    return climbStairsTabSO(n);
    }
};
