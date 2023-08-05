/*You are given an integer array nums.
 Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first.
 Both players start the game with a score of 0. At each turn, the player,
  takes one of the numbers from either end of the array (i.e., nums[0] or
   nums[nums.length - 1]) which reduces the size of the array by 1. The player adds,
    the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, 
then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

*/

class Solution {
public:
int predictWinnerRec(int s,int e,vector<int>& nums)
{
    if(s==e)
    {
        return nums[e];
    }
    int begin=nums[s]-predictWinnerRec(s+1,e,nums);
    int end=nums[e]-predictWinnerRec(s,e-1,nums);

    return max(begin,end);
}
int predictWinnerMemo(int s,int e,vector<int>& nums,vector<vector<int>>&dp)
{
    if(s==e)
    {
        return nums[e];
    }
    if(dp[s][e]!=-1)
    {
        return dp[s][e];
    }
    int begin=nums[s]-predictWinnerMemo(s+1,e,nums,dp);
    int end=nums[e]-predictWinnerMemo(s,e-1,nums,dp);

    return  dp[s][e]=max(begin,end);
}
int predictWinnerTab(vector<int>& nums)
{
    vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));

    for(int s=0;s<nums.size();s++)
    {
        
                dp[s][s]=nums[s];
            
        
    }
    
     for(int s=nums.size()-2;s>=0;s--)
    {
        for(int e=s+1;e<nums.size();e++){
            int begin=nums[s]-dp[s+1][e];
    int end=nums[e]-dp[s][e-1];

     dp[s][e]=max(begin,end);
        }
    }

    return dp[0][nums.size()-1];

}
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        if(nums.size()%2==0)
        {
            return true;
        }
        //return (predictWinnerRec(0,nums.size()-1,nums))>=0;
       // return (predictWinnerMemo(0,nums.size()-1,nums,dp))>=0;
       return (predictWinnerTab(nums))>=0;
    }
};