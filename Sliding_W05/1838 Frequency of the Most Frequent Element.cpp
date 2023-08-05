/*The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k.
 In one operation, you can choose an index of nums and increment the element
  at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.*/

// Basic Template followed

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long i=0,ans=1,sum=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];

            while(((j-i+1)*nums[j])-sum>k)
            {
                sum-=nums[i++];
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};

