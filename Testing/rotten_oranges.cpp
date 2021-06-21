// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        stack<pair<int, int>> s1, s2;
        int m=grid.size(), n=grid.at(0).size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid.at(i).at(j) == 2){
                    s1.push({i, j});
                }
            }
        }
        int ans{};
        
        while(!s1.empty() || !s2.empty()){
            int flag = 0;
            while(!s1.empty()){
                pair<int, int> p = s1.top();
                s1.pop();
                // top
                if(p.first-1 >= 0 && p.second >=0 && p.first-1 < m && p.second < n){
                    if(grid.at(p.first-1).at(p.second) == 1){
                        grid.at(p.first-1).at(p.second) = 2;
                        s2.push({p.first-1, p.second});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
                // bottom
                if(p.first+1 >= 0 && p.second >=0 && p.first+1 < m && p.second < n){
                    if(grid.at(p.first+1).at(p.second) == 1){
                        grid.at(p.first+1).at(p.second) = 2;
                        s2.push({p.first+1, p.second});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
                // left
                if(p.first >= 0 && p.second-1 >=0 && p.first < m && p.second-1 < n){
                    if(grid.at(p.first).at(p.second-1) == 1){
                        grid.at(p.first).at(p.second-1) = 2;
                        s2.push({p.first, p.second-1});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
                // right
                if(p.first >= 0 && p.second+1 >=0 && p.first < m && p.second+1 < n){
                    if(grid.at(p.first).at(p.second+1) == 1){
                        grid.at(p.first).at(p.second+1) = 2;
                        s2.push({p.first, p.second+1});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
            }
            flag = 0;
            
            while(!s2.empty()){
                pair<int, int> p = s2.top();
                s2.pop();
                // top
                if(p.first-1 >= 0 && p.second >=0 && p.first-1 < m && p.second < n){
                    if(grid.at(p.first-1).at(p.second) == 1){
                        grid.at(p.first-1).at(p.second) = 2;
                        s1.push({p.first-1, p.second});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
                // bottom
                if(p.first+1 >= 0 && p.second >=0 && p.first+1 < m && p.second < n){
                    if(grid.at(p.first+1).at(p.second) == 1){
                        grid.at(p.first+1).at(p.second) = 2;
                        s1.push({p.first+1, p.second});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
                // left
                if(p.first >= 0 && p.second-1 >=0 && p.first < m && p.second-1 < n){
                    if(grid.at(p.first).at(p.second-1) == 1){
                        grid.at(p.first).at(p.second-1) = 2;
                        s1.push({p.first, p.second-1});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
                // right
                if(p.first >= 0 && p.second+1 >=0 && p.first < m && p.second+1 < n){
                    if(grid.at(p.first).at(p.second+1) == 1){
                        grid.at(p.first).at(p.second+1) = 2;
                        s1.push({p.first, p.second+1});
                        if(!flag){
                            flag = 1;
                            ans++;
                        }
                    }  
                }
            }
            flag = 0;
        }
    
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid.at(i).at(j) == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends