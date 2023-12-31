/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.*/
/*Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109*/
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int>mp;
//         int n=nums.size();
//        int ans;
//         for(int i=0;i<n;i++)
//         {
//             mp[nums[i]]++;
//         }
//         for(auto it:mp)
//         {
//             if(it.second>(n/2))
//            { 
//                return it.first;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //sol2 using moores voting algo
        int el=INT_MIN,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el)
            cnt++;
            
            else
            cnt--;
        }
        cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el)
            cnt++;

            if(cnt>(nums.size()/2))
            return el;
        }
        return -1;
    }
};