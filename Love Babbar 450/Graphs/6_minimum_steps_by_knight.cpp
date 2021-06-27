// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    int i=KnightPos[1]-1, j=KnightPos[0]-1;
	    int t_i=TargetPos[1]-1, t_j=TargetPos[0]-1;
	    int size = N;
	    int x_add[]{-2, -1, 1, 2, 2, 1, -1, -2};
	    int y_add[]{1, 2, 2, 1, -1, -2, -2, -1};
	    int visited[size][size];
	    int distance[size][size];
	    memset(visited, 0, sizeof(visited));
	    memset(distance, -1, sizeof(distance));
	    queue<pair<int,int>> q;
	    q.push({i, j});
	    distance[i][j]=0;
	    visited[i][j] = 1;
	    while(!q.empty()){
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        for(int k=0; k<8; k++){
	            int new_x = x+x_add[k], new_y = y+y_add[k];
	            if(new_x>=0 && new_x < size && new_y>=0 && new_y<size){
	                if(!visited[new_x][new_y]){
	                    q.push({new_x, new_y});
	                    distance[new_x][new_y] = distance[x][y]+1;
	                    visited[new_x][new_y] = 1;
	                }
	            }
	        }
	    }
	    return distance[t_i][t_j];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends