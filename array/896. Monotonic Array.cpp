/*An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. 
An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.*/

/*Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105*/
//sol1
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc=0,dec=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                inc=1;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                dec=1;
            }
        }
        if(inc==0|| dec==0)
        return 1;

        else
        return 0;
        
    }
};

//sol2
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1)
        return 1;
        int inc=0,dec=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                inc=1;
            }
           else if(nums[i]<nums[i+1])
            {
                dec=1;
            }

            if(inc&&dec)
            return 0;
        }
        
       return 1;
        
    }
};