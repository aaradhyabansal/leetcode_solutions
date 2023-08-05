/*You are given an array of integers nums, there is a sliding window of size k which is moving from,
 the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        //*step1*pehle k size ki window ko process kro

        for(int i=0;i<k;i++)
        {
            while(!dq.empty()&& nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //*step2*store the ans of the first window processed

        ans.push_back(nums[dq.front()]);

         

        //*step3*process the remaining window

        for(int i=k;i<nums.size();i++)
        {
            //*step3a*remove out of bound elements

            if(!dq.empty()&& (i-dq.front()>=k))
            {
                dq.pop_front();
            }
            //*step3b*insert new  elements
            while(!dq.empty()&& nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            //*step3c*store the ans of the window processed
            ans.push_back(nums[dq.front()]);
        } 
        return ans;
    }
};