/*Given a binary array nums and an integer goal,
return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.*/

class Solution {
public:

    int numSubarraysWithSumAtMost(vector<int>& nums, int k)
    {
        if(k<0)
        return 0;

        int i=0,res=0;

        for(int j=0;j<nums.size();j++)
        {
          //update the value of k
            k-=nums[j];
//if k<0 means we have found our subarray,hence slide window for the next subarray/solution
            while(k<0)
            {
                k+=nums[i];
                i++;
            }
//update the value of res(idhar res+=j-i+1 islie kra hai coz let j=2 and i=0 ,no.of subarrays of length 2=3 so with res+=j-i+1 we achieve this)
            res+=(j-i+1);
        }
        //res return krdo
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
//ans will be like diff of k and k-1(utni subarrays)(pnc)
        return numSubarraysWithSumAtMost(nums,goal)-numSubarraysWithSumAtMost(nums,goal-1);
    }
};