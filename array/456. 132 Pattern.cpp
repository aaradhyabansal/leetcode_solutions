/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i],
 nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 */
/*Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109*/

//sol1 only works for contiguous elements
//fails for [3,5,0,3,4] types of cases
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]<nums[i+1]&& nums[i+2]<nums[i+1] && nums[i]<nums[i+2])
            {
                return true;
            }
        }
        return false;
        
    }
};

//sol2 brute force algorithm

use 3 nested loops and find the pattern exists or mot 
but but but 
T.C.->(O(n^3))

//sol using stack pattern matching bracket jaisa 

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>minA(n,0);
        minA[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            minA[i]=min(minA[i-1],nums[i]);
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=minA[i])
            st.pop();

            if(!st.empty()&& st.top()<nums[i])
            return true;

            st.push(nums[i]);
        }
        return false;
        
    }
};
