/*You are given an integer array nums. A number x is lonely when
 it appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) 
 appear in the array.

Return all lonely numbers in nums. You may return the answer in any order.

*/
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>st;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            st[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(st[nums[i]]==1 && st[nums[i]-1]==0 &&st[nums[i]+1]==0)
            {
                ans.push_back(nums[i]);
            }

        }
        return ans;
    }
};