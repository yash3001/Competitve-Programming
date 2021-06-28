// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        // void dfs(int n, int d, vector<int> &dist, vector<int> &visited, vector<vector<int>> &adj){
        //     visited.at(n) = 1;
        //     distance.at(n) = d;
        //     for(int i=0; i<adj.at(n).size(); i++){
        //         dfs(adj.at(n).at(i), d+1, )
        //     }
        // }
        vector<vector<int>> adj(n+1);
        vector<int> dist(n+1, 0), visited(n+1, 0);
        for(int i=1; i<n+1; i++){
            if(i+1<=n){
                adj.at(i).push_back(i+1);
            }
            if(3*i <= n){
                adj.at(i).push_back(3*i);
            }
        }
        //dfs(1, 0, dist, visited, adj);
        queue<int> q;
        q.push(1);
        visited.at(1) = 1;
        dist.at(1) = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<adj.at(node).size(); i++){
                if(!visited.at(adj.at(node).at(i))){
                    q.push(adj.at(node).at(i));
                    visited.at(adj.at(node).at(i)) = 1;
                    dist.at(adj.at(node).at(i)) = dist.at(node)+1;
                    if(adj.at(node).at(i) == n){
                        break;
                    }
                }
            }
        }
        for(int i =1; i<n+1; i++){
            for(int j=0; j<adj.at(i).size(); j++){
                cout<<i<<"->"<<adj.at(i).at(j)<<endl;
            }
        }
        return dist.at(n);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 

  // } Driver Code Ends