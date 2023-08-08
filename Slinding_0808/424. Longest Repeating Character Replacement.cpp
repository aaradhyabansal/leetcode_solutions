/*You are given a string s and an integer k.
 You can choose any character of the string and change it to
  any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter,
 you can get after performing the above operations.

*/
// Solved using shrinking sliding window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,n=s.length(),ans=0,j=0,cnt[26]={};
      while(j<n)
      {
          cnt[s[j++]-'A']++;
          while(j-i-*max_element(cnt,cnt+26)>k)
          {
              cnt[s[i++]-'A']--;
          }
          ans=max(ans,j-i);

      }
      return ans;
    }
};