/*You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.*/
/*Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000*/


//Recursive Solution TLE

class Solution {
public:

int coinChangeRec(vector<int>& coins,int amt,int index)
{
    if(index==0)
    {
        return (amt%coins[0] ==0);
    }

    int notTake=coinChangeRec(coins,amt,index-1);
    int take=0;
    if(coins[index]<=amt)
    take=coinChangeRec(coins,amt-coins[index],index);

    return take+notTake;

}

    int change(int amount, vector<int>& coins) {
        int amt=amount;
        return coinChangeRec(coins,amt,coins.size()-1);
    }
};

//MEMOISATION solution less optimised but works

class Solution {
public:

int coinChangeRec(vector<int>& coins,int amt,int index)
{
    if(index==0)
    {
        return (amt%coins[0] ==0);
    }

    int notTake=coinChangeRec(coins,amt,index-1);
    int take=0;
    if(coins[index]<=amt)
    take=coinChangeRec(coins,amt-coins[index],index);

    return take+notTake;

}
int coinChangeMemoi(vector<int>& coins,int amt,int index,vector<vector<int>>&dp)
{
    if(index==0)
    {
        return (amt%coins[0] ==0);
    }
    if(dp[index][amt]!=-1)
    return dp[index][amt];

    
    int take=0;
    if(coins[index]<=amt)
    take=coinChangeMemoi(coins,amt-coins[index],index,dp);

int notTake=coinChangeMemoi(coins,amt,index-1,dp);
    return dp[index][amt]=take+notTake;

}


    int change(int amount, vector<int>& coins) {
        int amt=amount;
        vector<vector<int>>dp(coins.size(),vector<int>(amt+1,-1));
       // return coinChangeRec(coins,amt,coins.size()-1);
        return coinChangeMemoi(coins,amt,coins.size()-1,dp);
    }
};