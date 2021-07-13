// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        unordered_map<int, int> mp;
        int sum=0;
        static int ans[]={1, 0};
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            if(mp[arr[i]] == 2){
                ans[0] = arr[i];
            }
            sum += arr[i];
        }
        ans[1] = (int)((n*(n+1))/2)-sum-ans[0];
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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends