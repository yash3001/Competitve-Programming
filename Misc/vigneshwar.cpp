#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        // input
        int n; cin>>n;
        int arr[n], ans[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int r; cin>>r;

        // rotating
        int j=0;
        for(int i=r; i<n; i++){
            ans[j++] = arr[i]; 
        }
        for(int i=0; i<r; i++){
            ans[j++] = arr[i];
        }
        
        //output
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}