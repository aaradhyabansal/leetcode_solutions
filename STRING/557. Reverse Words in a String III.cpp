/*Given a string s, reverse the order of characters in each word within a sentence,
 while still preserving whitespace and initial word order.*/
 /*Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.*/

//SOL1 using sliding window

class Solution {
public:
    void reverseString(string& s,int i,int j)
    {
        int n=j-i+1;
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int i=0,j=0;
        while(j!=s.length())
        {
            if(s[j]==' ')
            {
                reverseString(s,i,j-1);
                i=j+1;
                j++;
            }
            j++;
            
        }
        reverseString(s,i,j-1);
        return s;
    }
};

//sol2 suing stack
class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        string str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                st.push(s[i]);
            }
            else
            {
                while(!st.empty())
                {
                str+=st.top();
                st.pop();
                }
                str+=' ';
            
            }
        }
        //ek aur baar krna hoga coz last word not reverses
        //idhar galti hogi
        while(!st.empty())
                {
                str+=st.top();
                st.pop();
                }
        return str;
    }
};