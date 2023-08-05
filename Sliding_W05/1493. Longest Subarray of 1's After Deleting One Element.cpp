/*Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's 
in the resulting array. Return 0 if there is no such subarray.*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,ans=0,cnt=0,n=nums.size();
        for(int j=0;j<n;j++)
        {
            if(nums[j]==0)
            cnt++;

            while(cnt>1 && i<j)
            {
                if(nums[i]==0)
                cnt--;
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};