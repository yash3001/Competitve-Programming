#include <bits/stdc++.h>
#define ll long long 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define pb push_back
#define buffer cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
#define class_operator bool operator < (const movie & rhs) const {return en<rhs.en;}

using namespace std;


int main()
{
		int m1,m2;
		cin>>m1>>m2;
		int m=m1+m2;
		int n;
		cin>>n;
		vector <int> a(n);
		int sum=0;
		for(int i=0; i<n; i++){
			cin>>a[i];
			sum+=a[i];
		}
		bool dp[2][sum + 1];
		  for (int i = 0; i <= n; i++) {
		    for (int j = 0; j <= sum; j++) {
		      if (j == 0)
		        dp[i % 2][j] = true;
		      else if (i == 0)
		        dp[i % 2][j] = false;
		      else if (a[i - 1] <= j)
		        dp[i % 2][j] = dp[(i + 1) % 2][j - a[i - 1]] || dp[(i + 1) % 2][j];
		      else
		        dp[i % 2][j] = dp[(i + 1) % 2][j];
		    }
		  }
		int mi=INT_MAX;
		for(int i=0; i<=n; i++){
			for(int j=0; j<=sum; j++){
				if(dp[i%2][j]){
					int temp1=min(j,sum-j);
					int temp11=max(j,sum-j);
					int temp2=min(m1,m2);
					int temp21=max(m1,m2);
					int temp=max(temp1*temp21,temp2*temp11);
					mi=min(mi,temp);
				}
			}
		}
		cout<<mi<<endl;
		
	//look down
	return 0;
}