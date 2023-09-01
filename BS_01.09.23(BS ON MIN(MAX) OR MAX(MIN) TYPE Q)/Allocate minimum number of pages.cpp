/*PRESENT ON GFG :( NOT ON LEETCODE*/
/*You have N books, each with Ai number of pages. 
M students need to be allocated contiguous books, with each student getting at least one book. 
Out of all the permutations, the goal is to find the permutation where the student with the,
 most books allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).*/
/*Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}
Your Task:
You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= A [ i ] <= 106
1 <= M <= 105

*/

//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    
    
    int minOfMaxPages(int A[], int N, int possPage)
    {
        int stCnt=1;
        long long totPages=0;
        for(int i=0;i<N;i++)
        {
            if(totPages+A[i]<=possPage)
            {
                totPages+=A[i];
            }
            else
            {
                stCnt++;
                totPages=A[i];
            }
        }
        return stCnt;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
        return -1;
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<N;i++)
        {
            maxi=max(maxi,A[i]);
            sum+=A[i];
        }
        int low=maxi,high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int cntStudent=minOfMaxPages(A,N,mid);
            if(cntStudent>M)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends