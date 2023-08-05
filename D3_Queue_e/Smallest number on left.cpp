//{ Driver Code Starts
// Initial Template for C++
/*

Given an array a of integers of length n, find the nearest smaller number 
for every element such that the smaller element is on left side.
If no small element present on the left print -1.
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            int curr=a[i];
            while(st.top()>=curr)
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    
    return 0;
}
// } Driver Code Ends