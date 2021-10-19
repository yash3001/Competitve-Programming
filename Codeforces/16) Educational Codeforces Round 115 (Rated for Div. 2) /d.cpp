#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN=2147483647;
int t,n;
int a[201000],b[201000];
ll c[201000],d[201000];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			c[i]=d[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			c[a[i]]++;
			d[b[i]]++;
		}
		ll sum=1ll*n*(n-1)*(n-2)/6;
		for(int i=1;i<=n;i++)
			sum-=(c[a[i]]-1)*(d[b[i]]-1);
		printf("%lld\n",sum);
	}
	return 0;
}