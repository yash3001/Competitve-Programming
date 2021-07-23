// { Driver Code Starts
#include <bits/stdc++.h>
 
using namespace std;
 

 // } Driver Code Ends
class Solution{
public:
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        // Code Here
        for(const auto &v: V){
            if(v.size() != 0)
            cout<<v.at(0)<<" "<<v.at(1)<<endl;
        }
        return 0;
    }
};

// { Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }    
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}  // } Driver Code Ends