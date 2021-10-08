#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using namespace boost::multiprecision;

#define int long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define MOD 1000000007
#define test int t;cin>>t;while(t--)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef set<int> SI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, PII> PIII;

int poww(int n,int r)
{
    int res=1;
    while(r)
    {
        if(r&1)
        res=(res*n);
        n=(n*n);
        r=r>>1;
    }
    return res;
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

vector<vector<int>> adj;
vector<int> hd;
vector<int> dis,vis;
vector<vector<int>> rec;

void dfs(int u)
{
    if(vis[u])
    return;
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(vis[v]==0)
        {
           
            dis[v]=dis[u]+1;
            dfs(v);
           
        }
    }
}
void solve()
{
    int n,k;
    cin >> n >> k;
    adj.assign(n+1,{});
    hd.resize(n+1);
    
    for(int i=0; i<k; i++)
    {
        int x;
        cin >> x;
        hd[x]=1;
    }

    for(int i=0; i<n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ctr = 0;
    for(int i=1;i<=n;i++)
    {
        if(hd[i])
        {
            dis.assign(n+1,0);
            vis.assign(n+1,0);
        
            dfs(i);
            ctr++;

            for(int j=1;j<=n;j++)
            {
                if(hd[j])
                {
                    rec.PB({dis[j],i,j});
                }
            }

        }
        if(ctr==k/2)
        break;
       
    }

    unordered_map<int,int> mp;
    sort(rec.rbegin(), rec.rend());
    int ans = 0;
    for(int i=0;i<rec.size();i++)
    {
        int cost = rec[i][0];
        int x = rec[i][1];
        int y = rec[i][2];
        if(mp[x]==0 && mp[y]==0)
        {
            ans+=cost;
            mp[x]=1;
            mp[y]=1;
        }
    }
    cout << ans << "\n";

}

int32_t main()
{
    solve();
    return 0;
}