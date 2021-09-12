#include<bits/stdc++.h>
#include <iomanip>
#include<fstream>
using namespace std;
#define swap(a,b) {int t=a;a=b;b=t;}
#define F(i,n) for(int i=0;i<n;i++)
#define Fr(i,j,n) for(int i=j;i<=n;i++)
#define ll long long 
#define ld long double 
#define d double 
#define ull unsigned long long 
#define mod 1000000007

long long solve3(){
    int n;
    cin>>n;
   
   string s;
   cin>>s;
   long long Ans=0,add1=0,add=0,S_tore=0;
   char Previous ='N';
   int flag =0;
   while(!s.empty()){
       if(s.back()=='F'|| s.back()==Previous || Previous=='N'){
           
           Ans=(Ans+add1)%mod;
           if(((s.back()!='F' )&& flag==0)||(Previous=='N') ){
              
               add++;
           } 
           else{
               S_tore ++;
               flag=1;
               if(Previous==s.back()){
                   add+=S_tore;
                   S_tore=0;
                   flag=0;
               }
           }
       }
       else{
           add1=(add1+add);
           Ans=(Ans+add1)%mod;
           add++;
           add+=S_tore;
           S_tore=0;
           flag=0;
           Previous=s.back();
       }
       if(s.back()!='F') Previous=s.back();
       s.pop_back();
   }
   return Ans;
}

int main(){
ios::sync_with_stdio(true);
ofstream output("output.txt");
cin.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

int t=0;
cin>>t;
int i=1;
while(i<=t){
    int ans=solve3();
    cout <<"Case #"<<i<<": "<<ans<<"\n";

i++;
}
output.close();

return 0;
}