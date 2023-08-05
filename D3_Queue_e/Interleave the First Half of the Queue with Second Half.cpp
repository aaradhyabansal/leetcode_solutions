//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
You are given a queue Q of N integers of even length, 
rearrange the elements by interleaving ,
the first half of the queue with the second half of the queue.

*/
// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int>ans;
        queue<int>q1;
        int n=q.size()/2;
        int k=q.size()-n;
        while(n!=0)
        {
            q1.push(q.front());
            q.pop();
            n--;
        }
        while(k)
        {
            int fronti=q.front();
            q.pop();
            q.push(q1.front());
            q1.pop();
            q.push(fronti);
            k--;
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
   
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
    
    return 0;
}
// } Driver Code Ends