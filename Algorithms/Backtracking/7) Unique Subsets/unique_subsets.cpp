// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find all possible unique subsets.
    
    void solve(int i, vector<int> subs, vector<vector<int>> &ans, vector<int> arr, int n, unordered_map<string, int> &mp){
        if(i == n){
            sort(subs.begin(), subs.end());
            string s;
            for(int i=0; i<subs.size(); i++){
                s.push_back(subs[i]);
            }
            if(!mp[s]){
                ans.push_back(subs);
                mp[s]++;
            }
        }
        
        else{
            solve(i+1, subs, ans, arr ,n, mp);
            subs.push_back(arr[i]);
            solve(i+1, subs, ans, arr, n, mp);
            subs.pop_back();
        }
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<int> subs;
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        
        solve(0, subs, ans, arr, n, mp);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends