// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

    vector<string> permutation(string S){
        // Code Here
        vector<string> ans;
        int n = S.size()-1;
        for(int i=0; i<(1<<n); i++){
            string s;
            s.push_back(S.at(0));
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    s.push_back(' ');
                    s.push_back(S.at(j+1));
                }
                else{
                    s.push_back(S.at(j+1));
                }
            }
            ans.push_back(s);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends