#include<bits/stdc++.h>
using namespace std;

string encryptCaesar(string& str,unordered_map<int,char>&alpha,unordered_map<char,int>& num,int m)
{
    string arr="";
    for(int i=0;i<str.length();i++)
    {
        int k=num[str[i]];
        k=(k+m)%26;
        arr+=alpha[k];
    }
    return arr;
}

string decryptCaesar(string& str,unordered_map<int,char>&alpha,unordered_map<char,int>& num,int m)
{
    string arr="";
    for(int i=0;i<str.length();i++)
    {
        int k=num[str[i]];
        k=(k-m)%26;
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
   string str;

 
   cout<<"enter string to be encrypted"<<endl;
   getline(cin,str);
    cout<<"enter the value of caesar coeff."<<endl;
  cin>>k;
  string encrypted=encryptCaesar(str,alpha,num,k);
  cout<<encrypted<<endl;
  string decrypted=decryptCaesar(encrypted,alpha,num,k);
  cout<<decrypted<<endl;
   
}