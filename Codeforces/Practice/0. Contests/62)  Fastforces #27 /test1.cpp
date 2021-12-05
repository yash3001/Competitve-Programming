#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
vector<int> level(N);
vector<vector<int> > yash(20, vector<int>(N));
vector<vector<int> > mx(20, vector<int>(N));
vector<vector<pair<int, int>>> v(N);

vector<int> parent(100005, -1);

int find(int n){
    if(parent[n] == -1){
        return n;
    }
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    parent[a] = b;
}

void fand(int n){
    for (int i=1; i<20; i++){
        for (int j = 1; j <= n; j++){
            yash[i][j] = yash[i-1][yash[i-1][j]];
            mx[i][j] = max(mx[i-1][j], mx[i-1][yash[i-1][j]]);
        }
    }
}

void lca(int a, int par, int lev){
    yash[0][a] = par;
    level[a] = lev;
    for(auto i:v[a]) {
        if(i.first == par){
            continue;
        }
        mx[0][i.first] = i.second;
        lca(i.first,a,lev+1);
    }
}

int getMax(int a, int b){
	if (level[b]<level[a]){
		swap(a, b);
    }
	int ans = 0;
	int diff = level[b] - level[a];
	while (diff > 0) {
		int log = log2(diff);
		ans = max(ans, mx[log][b]);
		b = yash[log][b];
		diff -= (1 << log);
	}

	while (a != b){
		int i = log2(level[a]);
		while (i > 0 && yash[i][a] == yash[i][b]){
            i--;
        }
		ans = max(ans, mx[i][a]);
		ans = max(ans, mx[i][b]);
		a = yash[i][a];
		b = yash[i][b];
	}
	return ans;
}

void compute_lca(int n){
	lca(1, 0, 0);
	fand(n);
}

int rec(int src, int dest, vector<int> &vis){
    if(src == dest){
        return 0;
    }
    vis[src] = true;
    int ans = 1e9;
    for(auto i:v[src]){
        if(!vis[i.first]){
            ans = max(ans, min(rec(i.first, dest, vis), i.second));
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    int m; cin>>m;
	int q; cin>>q;
    vector<vector<int>> inp;
    for(int i=0; i<m; i++){
        vector<int> t(3); cin>>t[0]>>t[1]>>t[2];
        int a = find(t[0]);
        int b = find(t[1]);
        if(a != b){
            merge(a, b);
        }
        inp.push_back(t);
    }

    // our code
    for(int i=0; i<m; i++){
        vector<int> t = inp[i];
        int a = t[0];
        int b = t[1];
        int c = t[2];
        v[a].push_back({b, c});
    }
	compute_lca(n);

	for (int i = 0; i < q; i++) {
        int a, b; cin>>a>>b;
        if(find(a) != find(b)){
            cout<<-1<<endl;
        }
        else{
            vector<int> vis(n+1, 0);
		    int max_edge = rec(a, b, vis);
		    cout << max_edge << endl;
        }
	}
	return 0;
}
