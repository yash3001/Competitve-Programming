#include<bits/stdc++.h>
using namespace std;
    bool flag=true;
    bool status=false;
void kaprekarNumbers(int p, int q) {
 for(int i=p;i<=q;i++)
 { 

  int num=pow(i,2);
//   cout<<"num"<<num<<endl;
  int s=0,j=0;
  while(num>0)
  {
    int d=num%10;
    // cout<<"d= "<<d<<endl;
    s+=d*(pow(10,j));
    // cout<<"s= "<<s<<endl;
    if(s!=0)
    {
      status=true;  
    }
     
    num=num/10;
    // cout<<"num= "<<num<<endl;
    j++;
    if(status==true && (s+num==i))
     {
        cout<<s<<" "<<num<<" "<<s+num<<" "<<i<<endl;
      flag=false;
      break;
     }
  }    
 }
//  if(flag)
//   cout<<"INVALID RANGE";
}

int main()
{
  kaprekarNumbers(1,100);
 return 0;
}