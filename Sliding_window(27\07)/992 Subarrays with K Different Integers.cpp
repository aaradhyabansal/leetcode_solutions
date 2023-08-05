/*Given an integer array nums and an integer k,
return the number of good subarrays of nums.

A good array is an array where the number of different ,
integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/

class Solution {
public:

    int subarraysWithKDistinctAtMost(vector<int>& nums, int k)
    {
        // int res=0,i=0;
        // unordered_map<int,int>charCount;
        // for(int j=0;j<nums.size();j++)
        // {
        //    charCount[nums[j]]++;
        //    if(charCount[nums[j]]==1)
        //        k--;

        //    while(k<0)
        //    {
        //        charCount[nums[i]]--;
        //        if(charCount[nums[i]]==0)
        //      k++;
        //      i++;
        //    }
        //    res+=j-i+1;
        // }
        // cout<<res<<endl;
        // return res;
        int i=0,p=0,d=0,r=0;
        unordered_map<int,int>charCount;
        for(int j=0;j<nums.size();j++)
        {
            charCount[nums[j]]++;

            if(charCount[nums[j]]==1)
            d++;

            if(d>k)
            {
                charCount[nums[i]]--;
                p=0;
                d--;
                i++;
                
            }

            while(charCount[nums[i]]>1)
            {
                charCount[nums[i]]--;
                i++;
                p++;
            }
            if(d==k)
            r+=p+1;
        }
        return r;
        
    }

    // int subarraysWithKDistinct(vector<int>& nums, int k) {
    //     return  subarraysWithKDistinctAtMost(nums,k)-subarraysWithKDistinctAtMost(nums,k-1);
    // }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return  subarraysWithKDistinctAtMost(nums,k);
    }
};