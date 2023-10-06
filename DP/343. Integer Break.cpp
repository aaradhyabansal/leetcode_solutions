/*Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

*/
/*Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:

2 <= n <= 58*/

class Solution {
public:

int intBreakRec(int n)
{
    if(n==0)
    return 0;
    if(n==1||n==2)
    return 1;

    int ans=0;
    for(int i=1;i<=n/2;i++)
    {
       ans=max(ans,max(i,intBreakRec(i))*max(n-i,intBreakRec(n-i)));
    }
    return ans;

}

    int integerBreak(int n) {
        return intBreakRec(n);
    }
};