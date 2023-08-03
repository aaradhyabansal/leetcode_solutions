/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence 
of all these characters a, b and c.*/

class Solution {
public:
int numberOfSubStr(string& s)
{
    vector<int>freq(3,0);
    int i=0,r=0,p=0,dist=0;
    for(int j=0;j<s.length();j++)
    {
        if(freq[s[j]-'a']==0)
        dist++;

        freq[s[j]-'a']++;

         while(freq[s[i]-'a']>1 && i<j)
         {
             freq[s[i]-'a']--;
             i++;
             p++;
         }
         if(dist==3)
         r+=p+1;
    }
    return r;
}


    int numberOfSubstrings(string s) {
       return numberOfSubStr(s);
    }
};