/*Given a string s, find the length of the longest 
substring
 without repeating characters.*/

 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,n=s.length(),ans=0,cnt[128]={};
        for(int j=0;j<n;j++)
        {
            cnt[s[j]]++;
            while(cnt[s[j]]>1)
            {
                cnt[s[i++]]--;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char,int>charfreq;
//         int i=0,res=0;
//         for(int j=0;j<s.size();j++)
//         {
//             charfreq[s[j]]++;
            
//             while(charfreq[s[j]]>1)
//             {
//                 charfreq[s[i]]--;
//                 i++;
//             }
//             res=max(res,j-i+1);
//         }
//         return res;
//     }
// };