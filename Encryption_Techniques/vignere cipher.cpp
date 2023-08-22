#include<bits/stdc++.h>
using namespace std;

string encryptCaesar(string& str,unordered_map<int,char>&alpha,unordered_map<char,int>& num,string&keyw)
{
    string arr="";
    for(int i=0;i<str.length();i++)
    {
        int k=num[str[i]];
      k=(k+keyw[i])%26;
        arr+=alpha[k];
    }
    return arr;
}

string decryptCaesar(string& str,unordered_map<int,char>&alpha,unordered_map<char,int>& num,string&keyw)
{
    string arr="";
    for(int i=0;i<str.length();i++)
    {
        int k=num[str[i]];
        k=(k-keyw[i])%26;
        if(k<0)
        k+=26;
        arr+=alpha[k];
    }
    return arr;
}

int main()
{
    char ch='a';
       int k;
   unordered_map<int,char>alpha;
   for(int i=0;i<26;i++)
   {
       alpha[i]=ch;
       ch++;
   }
   int j=0;
   unordered_map<char,int>num;
   for(char i='a';i<='z';i++)
   {
       num[i]=j;
       j++;
   }
   string str,keyw,nkeyw;

 
   cout<<"enter string to be encrypted"<<endl;
   getline(cin,str);
   int n=str.length(),i=0;
    cout<<"enter the keyword"<<endl;
   getline(cin,keyw);
   nkeyw=keyw;
   while(keyw.length()!=str.length())
   {
       if(i==nkeyw.length())
       i=0;
       
       keyw+=nkeyw[i++];
   }
  string encrypted=encryptCaesar(str,alpha,num,keyw);
  cout<<encrypted<<endl;
  string decrypted=decryptCaesar(encrypted,alpha,num,keyw);
  cout<<decrypted<<endl;
   
}
