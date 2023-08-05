/*Based on parenthesis matching type*/
/*We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents ,
its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, 
the smaller one will explode. If both are the same size, both will explode.
 Two asteroids moving in the same direction will never meet.
*/

class Solution {
public:
void insertAtBottom(stack<int>&st,int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int topi=st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(topi);
}
void reverseStack(stack<int>&st)
{
    if(st.empty())
    {
        return;
    }
    int topi=st.top();
    st.pop();
    reverseStack(st);
   insertAtBottom(st,topi);
}


    vector<int> asteroidCollision(vector<int>& asteroids)
     {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++)
        {
            int curr=asteroids[i];
            if(curr>0)
            {
                st.push(curr);
            }
            else
            {
                 while (!st.empty() && st.top() > 0 && st.top() < abs(curr)) {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(curr)) {
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    st.push(curr);
                }

        }
        }
        reverseStack(st);
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
     }
     };