// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> ans;
    int x_add[4]={1, 0, 0, -1};
    int y_add[4]={0, -1, 1, 0};
    char c_add[4]={'D', 'L', 'R', 'U'};
    vector<vector<int>> grid;
    int size;
   
    public:

    bool isValid(int x, int y, vector<vector<int>> &visited){
        if(x>=0 && x<size && y>=0 && y<size && !visited.at(x).at(y)){
            if(grid.at(x).at(y)==1){
                return true;
            }
            return false;
        }
        return false;
    }

    void find_paths(string s, vector<string> &ans, int i, int j, vector<vector<int>> &visited){
        visited.at(i).at(j) = 1;
        if(i == size-1 && j == size-1){
            ans.push_back(s);
        }
        for(int k=0; k<4; k++){
            if(isValid(i+x_add[k], j+y_add[k], visited)){
                find_paths(s+c_add[k],ans,i+x_add[k], j+y_add[k],visited);
            }
        }
        visited.at(i).at(j) = 0;
    }
   
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes 
        vector<int> temp(n, 0);
        vector<vector<int>> visited(n, temp);
        grid = m;
        size = n;
        vector<string> ans;
        if(!isValid(0, 0, visited)){
            return ans;
        }
        find_paths("", ans, 0, 0, visited);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends