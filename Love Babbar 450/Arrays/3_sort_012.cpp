// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        coode here 
        unordered_map<int, long long int> mp;
        for(int i=0; i<n; i++){
            mp[a[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp[0] != 0){
                a[i] = 0;
                mp[0]--;
            }
            else if(mp[1] != 0){
                a[i] = 1;
                mp[1]--;
            }
            else{
                a[i] = 2;
                mp[2]--;
            }
        }
        
        // sort(a, a+n);
        
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends