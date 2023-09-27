/*A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
 it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/
/*Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s==" "||s=="")
        return 1;

        //vector<char>s1;
        string s1;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>64 && s[i]<91 )||(s[i]>96 && s[i]<123)||(s[i]>47 && s[i]<58))
            {
                s1+=tolower(s[i]);
            }
        }
        int i=0,j=s1.size()-1;
        for(int k=0;k<s1.size();k++)
        {
            cout<<s1[k];
        }
        while(i<j)
        {
            if(s1[i]!=s1[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1;

    }
};