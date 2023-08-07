/*You are given an array of positive integers nums and want
 to erase a subarray containing unique elements. The score you get 
 by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous
 subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,ans=0,sum=0;
        unordered_map<int,int>cnt;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            cnt[nums[j]]++;
            while(i<j && cnt[nums[j]]>1)
            {
                sum-=nums[i];
                cnt[nums[i]]--;
                i++;
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int i=0,ans=0,prev=0,sum=0,n=nums.size();
//         for(int j=0;j<n;j++)
//         {
//             sum+=nums[j];

//             while(i<j && nums[j]<prev)
//             {
//                 sum-=nums[i++];
//             }
//             ans=max(ans,sum);
//             prev=nums[j];
//         }
//         return ans;
//     }
// };