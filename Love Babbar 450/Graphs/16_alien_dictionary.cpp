// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        int check[K][K];
        memset(check, 0, sizeof(check));
        
        vector<vector<int>> adj(K);
        vector<int> indeg(K, 0), visited(K, 0);
        
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int min_size = min(s1.size(), s2.size());
            
            for(int j=0; j<min_size; j++){
                if(s1.at(j) == s2.at(j)){
                    continue;
                }
                int m = s1.at(j) - 'a';
                int n = s2.at(j) - 'a';
                if(!check[m][n]){
                    check[m][n] = 1;
                    adj.at(m).push_back(n);
                    indeg.at(n)++;
                }
                break;
            }
        }
        queue<int> q;
        for(int i=0; i<K; i++){
            if(indeg.at(i)==0){
                q.push(i);
                visited.at(i) = 1;
                
            }
        }
        string ans;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            ans += (char)(n+'a');
            for(const auto &c: adj.at(n)){
                if(--indeg.at(c) == 0){
                    visited.at(c) = 1;
                    q.push(c);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends