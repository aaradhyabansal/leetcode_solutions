#include<bits/stdc++.h>
using namespace std;
string encryptRailFence(vector<vector<char>>&railFence,int c,int n,string& str)
{
    int i=0,j=0;
    string encrypted="";
     for(int k=0;k<str.length();k++)
   {
       if(i==n)
       i=0;
       railFence[i][j]=str[k];
       i++;j++;
       
   }
   
   for( i=0;i<n;i++)
   {
       for( j=0;j<c;j++)
       {
           if(railFence[i][j]!='-')
           encrypted+=railFence[i][j];
       }
   }
   return encrypted;
}
string decryptRailFence(vector<vector<char>>&railFence,int c,int n)
{
    string decrypted="";
     int k=0,i=0,j=0;
   while(k!=c)
   {
       if(i==n)
       i=0;
       decrypted+=railFence[i][j];
       i++;j++;k++;
   }
   return decrypted;
}
int main()
{
    int n;
    string str;
     cout<<"enter string to be encrypted"<<endl;
  getline(cin,str);
    cout<<"enter the depth of cipher"<<endl;
    cin>>n;
    int c=str.length();
    vector<vector<char>>railFence(n,vector<char>(c,'-'));

   string encrypted=encryptRailFence(railFence,c,n,str);
   cout<<"encrypted->"<<encrypted<<endl;
   string decrypted=decryptRailFence(railFence,c,n);
   cout<<"decrypted->"<<decrypted<<endl;
}