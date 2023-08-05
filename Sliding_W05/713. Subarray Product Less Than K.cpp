/*Given an array of integers nums and an integer k, 
return the number of contiguous subarrays where the product of 
all the elements in the subarray is strictly less than k.

*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
        return 0;
        long i=0,prod=1,ans=0,n=nums.size();
        for(int j=0;j<n;j++)
        {
            prod*=nums[j];

            while(i<=j && prod>=k)
            {
                prod/=nums[i++];
            }
            ans+=j-i+1;
        }
        return ans;
    }
};