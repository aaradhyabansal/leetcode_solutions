/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

*/

/*Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104*/


class cmp{
    public:
    bool operator()(int& a,int& b)
    {
        return a>b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,cmp>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k;i<nums.size();i++)
        {
            if(pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();

    }
};