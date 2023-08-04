// // Given a string s and a dictionary of strings wordDict,
//  return true if s can be segmented into a space-separated 
//  sequence of one or more dictionary words.

// // Note that the same word in the dictionary may be reused multiple times in the segmentation.

class Solution {
public:
int wordBreakRec(int index,string& s,set<string>& st)
{
    if(index==s.length())
    {
        return 1;
    }
    string temp="";
    int ans=0;

    for(int i=index;i<s.length();i++)
    {
        temp+=s[i];
        if(st.find(temp)!=st.end()){
        if(wordBreakRec(i+1,s,st))
        return 1;

            }
        }
    
    return 0;
}
int wordBreakMemo(int index,string& s,set<string>& st,vector<int>& dp)
{
    if(index==s.length())
    {
        return 1;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    string temp="";
 

    for(int i=index;i<s.length();i++)
    {
        temp+=s[i];
        if(st.find(temp)!=st.end()){
        if(wordBreakMemo(i+1,s,st,dp))
        return dp[index]= 1;

            }
        }
    
    return dp[index]=0;
}
int wordBreakTab(string& s, set<string>& st)
{
     vector<int>dp(s.length()+1,0);
     dp[s.length()]=1;

     for(int index=s.length()-1;index>=0;index--)
     {
         string temp="";
 

    for(int i=index;i<s.length();i++)
    {
        temp+=s[i];
        if(st.find(temp)!=st.end()){
            cout<<temp<<endl;
        if(dp[i+1])
      dp[index]= 1;

            }
        }
     }
     return dp[0];
}

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        vector<int>dp(s.length(),-1);
        st.insert(wordDict.begin(),wordDict.end());
        // return wordBreakRec(0,s,st);
        //  return wordBreakMemo(0,s,st,dp);
        return wordBreakTab(s,st);
    }
};

