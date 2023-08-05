/*There are n cars traveling at different speeds in the same direction along a one-lane road. 
You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:
positioni is the distance between the ith car and the beginning of the road in meters. 
It is guaranteed that positioni < positioni+1.
speedi is the initial speed of the ith car in meters per second.
For simplicity, cars can be considered as points moving along the number line.
 Two cars collide when they occupy the same position. Once a car collides with another car, 
 they unite and form a single car fleet. The cars in the formed fleet will have the same
  position and the same speed,which is the initial speed of the slowest car in the fleet.
Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides
 with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.*/



 class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>ans(cars.size(),-1);
        stack<int>st;
        for(int i=cars.size()-1;i>=0;i--)
        {
            while(!st.empty()&& cars[st.top()][1]>=cars[i][1])
            {
                st.pop();
            }
            while(!st.empty())
            {
                double colTime=((double)cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(ans[st.top()]==-1||(colTime<=ans[st.top()]))
                {
                    ans[i]=colTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};