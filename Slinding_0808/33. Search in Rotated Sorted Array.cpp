/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an 
unknown pivot index k (1 <= k < nums.length) such that the 
resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/

//Solved Using map but not a good solution need to improve

class Solution {
public:
    int search(vector<int>& nums, int target) {
       
       int n=nums.size();
       unordered_map<int,pair<int,int>>st;
       for(int i=0;i<n;i++)
        {
            st[i]={-1,0};
        }
        for(int i=0;i<n;i++)
        {
            st[nums[i]]={i,1};
        }
        if(st[target].first>=0 && st[target].first<n && st[target].second !=0)
        return st[target].first;
           
        else
        return -1;
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         unordered_set<pair<int,int>>st;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             st.insert({nums[i],i});
//         }
//         unordered_set<pair<int,int>>sto=st.find(target);
//         if(!=st.end())
//         return ;
//         else
//         return false;
//     }
// };//isko explore kro cause O(1) mai ans milega baaki isse binary search se krna tha