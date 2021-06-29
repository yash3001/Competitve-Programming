// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    int xadd[8]={-1, -1, 0, 1, 1, 1, 0, -1};
    int yadd[8]={0, 1, 1, 1, 0, -1, -1, -1};
    int n, m;
    public:
    //Function to find the number of islands.
    
    bool isValid(int x, int y, vector<vector<int>> &visited, vector<vector<char>> &grid){
        if(x>=0 && x<n && y>=0 && y<m){
            if(!visited[x][y] && grid[x][y] == '1'){
                return true;
            }
            return false;
        }
        return false;
    }
        
    void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>> &grid){
        visited[x][y] = 1;
        for(int i=0; i<8; i++){
            if(isValid(x+xadd[i], y+yadd[i], visited, grid)){
                dfs(x+xadd[i], y+yadd[i], visited, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        n = grid.size();
        m = grid.at(0).size();
        
        vector<int> temp(m, 0);
        vector<vector<int>> visited(n, temp);
        
        int ans{};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(i, j, visited, grid);
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends