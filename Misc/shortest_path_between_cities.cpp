// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here
        if(x>y){
            swap(x, y);
        }
        vector<vector<int>> adj(y+1);
        queue<int> q;
        int n = 1;
        int k=1;
        for(int i=2; i<= y; i++){
            if(k==3){
                n = q.front();
                q.pop();
                k = 1;
            }
            adj.at(n).push_back(i);
            adj.at(i).push_back(n);
            q.push(i);
            k++;
        }
        // for(int i=1; i<=y; i++){
        //     cout<<i<<"->";
        //     for(const auto &c: adj.at(i)){
        //         cout<<c<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> dist(y+1, 0), visited(y+1, 0);
        queue<int> q1;
        q1.push(x);
        visited.at(x) = 1;
        while(!q1.empty()){
            int n = q1.front();
            q1.pop();
            
            for(const auto &c: adj.at(n)){
                if(!visited.at(c)){
                    q1.push(c);
                    visited.at(c) = 1;
                    dist.at(c) = dist.at(n) + 1;
                }
            }
        }
        
        
        return dist.at(y);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends