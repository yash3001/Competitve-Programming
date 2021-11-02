/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(26);

string Sexp(int root,int par){
	vector<int> val;
	for(auto i:graph[root]){
		if(i!=par){
			val.push_back(i);
		}
	}
	sort(val.begin(), val.end());
	string s1 = (val.size()>=1)? "(" + Sexp(val[0],root)+")" : "";
	string s2 = (val.size()>1)? "(" + Sexp(val[1],root)+"))" : "";
	char ch = root+'A';
	string temp = "";
	temp+=ch;
	string s = temp+s1  +  s2;
	return s;
}

void dfs(int n, vector<int> &vis){
    vis[n] = 1;
    for(const auto &c: graph[n]){
        if(!vis[c]){
            dfs(c, vis);
        }
    }
}

bool checkCycle(int n, int p, vector<int> &vis){
    vis[n] = 1;
    for(const auto &c: graph[n]){
        if(!vis[c]){
            if(checkCycle(c, n, vis)){
                return true;
            }
        }
        else{
            if(c != p){
                return true;
            }
        }
    }
    return false;
}

void solve(){
	string nodes;
	cin>>nodes;

	for(int i=1;i<nodes.length();i+=3){
		int u = (nodes[i]-'A');
		i+=2;
		int v = (nodes[i]-'A');
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

    for(int i=0; i<26; i++){
        map<int, int> mp;
        for(const auto &c: graph[i]){
            if(mp[c]++){
                cout<<"E2"<<endl;
                return;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<26; i++){
        for(const auto &c: graph[i]){
            cnt = 0;
            for(const auto &t: graph[c]){
                if(t != i){
                    if(cnt++ == 2){
                        cout<<"E1"<<endl;
                        return;
                    }
                }
            }
        }
    }
    for(int i=0; i<26; i++){
        if(graph[i].size() > 0){
            vector<int> vis(26, 0);
            if(checkCycle(i, -1, vis)){
                cout<<"E3"<<endl;
                return;
            }
            break;
        }
    }

    cnt = 0;
    vector<int> vis(26, 0);
    for(int i=0; i<26; i++){
        if(!vis[i] && graph[i].size()>0){
            dfs(i, vis);
            if(cnt++){
                cout<<"E4"<<endl;
                return;
            }
        }
    }

    if(nodes.size() == 0){
        cout<<"E5"<<endl;
        return;
    }
	cout<<"(" + Sexp(0,-1)<<endl;
}

int main(){
    solve();
}