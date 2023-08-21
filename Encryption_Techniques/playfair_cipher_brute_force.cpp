#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>>&diag,char ch)
{
    for(int i=0;i<diag.size();i++)
    {
        for(int j=0;j<diag.size();j++)
        {
            if(ch==diag[i][j])
            return false;
        }
    }
    return true;
}
pair<int,int>findChar(vector<vector<char>>&diag,char ch)
{
    for(int i=0;i<diag.size();i++)
    {
        for(int j=0;j<diag.size();j++)
        {
            if(ch==diag[i][j])
            return {i,j};
        }
    }
}
string encryptPlayfair(vector<vector<char>>&diag,string str)
{
     string arr="";
     if(str.length()%2!=0)
     {
         str+='x';
     }
     for(int i=0;i<str.length();i+=2)
{     
    char ch1,ch2;
    ch1=str[i];
    ch2=str[i+1];
    pair<int,int>p1,p2;
    p1=findChar(diag,ch1);
    p2=findChar(diag,ch2);
    if(p1.first==p2.first)
    {
        int val1=p1.second+1;
        int val2=p2.second+1;
        if(val1==5)
        {
            val1=0;
        }
        if(val2==5)
        {
            val2=0;
        }
        arr+=diag[p1.first][val1];
        arr+=diag[p2.first][val2];
   
        
    }
    else if(p1.second==p2.second)
    {
        int val1=p1.first+1;
        int val2=p2.first+1;
        if(val1==5)
        {
            val1=0;
        }
        if(val2==5)
        {
            val2=0;
        }
        arr+=diag[val1][p1.second];
       
    }
    else
    {
        int val1=p2.second;
        int val2=p1.second;
        arr+=diag[p1.first][val1];
        arr+=diag[p2.first][val2];
    }
    }
    return arr;
}
string decryptPlayfair(vector<vector<char>>&diag,string str)
{
     string arr="";
     for(int i=0;i<str.length();i+=2)
{     
    char ch1,ch2;
    ch1=str[i];
    ch2=str[i+1];
    pair<int,int>p1,p2;
    p1=findChar(diag,ch1);
    p2=findChar(diag,ch2);
    if(p1.first==p2.first)
    {
        int val1=p1.second-1;
        int val2=p2.second-1;
        if(val1==0)
        {
            val1=4;
        }
        if(val2==0)
        {
            val2=4;
        }
        arr+=diag[p1.first][val1];
        arr+=diag[p2.first][val2];
   
        
    }
    else if(p1.second==p2.second)
    {
        int val1=p1.first-1;
        int val2=p2.first-1;
        if(val1==0)
        {
            val1=4;
        }
        if(val2==0)
        {
            val2=4;
        }
        arr+=diag[val1][p1.second];
       
    }
    else
    {
        int val1=p2.second;
        int val2=p1.second;
        arr+=diag[p1.first][val1];
        arr+=diag[p2.first][val2];
    }
    }
    return arr;
}
string modifyString(string str)
{
    int n=str.length();
    string arr="";
    for(int i=0;i<n;i+=2)
    {
        char ch1,ch2;
        ch1=str[i];
    ch2=str[i+1];
    if(ch1==ch2)
    {
        arr+=ch1;
        arr+='x';
        arr+=ch2;
    }
    else
    {
        arr+=ch1;
        arr+=ch2;
    }
    }
    return arr;
}
int main()
{ int n=0,i=0,j=0,k=0;
string encrc="";
    vector<vector<char>>diag(5,vector<char>(5,'-'));
    string keyword="";
    cout<<"enter the keyword"<<endl;
    getline(cin,keyword);
    string encr="";
    cout<<"enter the word"<<endl;
    getline(cin,encr);
    encrc=encr;
   while(k!=keyword.size())
   {
       if(isSafe(diag,keyword[k]))
       {
           diag[i][j]=keyword[k];
           k++;
           j++;
           if(j==5)
           {
               i++;
               j=0;
           }
           
       }
       else
           {
               k++;
           }
   }
 
      for(char ch='a';ch<='z';ch++)
      {
          if(isSafe(diag,'i')==false && ch=='j'||isSafe(diag,'j')==false && ch=='i' )
          continue;

          if(isSafe(diag,ch))
          {
              diag[i][j]=ch;
              j++;
          if(j==5)
          {
              i++;
              j=0;
          }
          }
          else
          continue;
      
  }
   string arr=modifyString(encr);
   cout<<arr<<endl;
   string encrypted=encryptPlayfair(diag,arr);
   cout<<encrypted<<endl;
   string decrypted=decryptPlayfair(diag,arr);
   cout<<decrypted<<endl;
}