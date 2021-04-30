// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v(2);
    v.at(0)=lower_bound(arr, arr+n, x)-arr;
    v.at(1)=upper_bound(arr, arr+n, x)-arr-1;
    if(arr[v.at(0)]!=x){
        v.at(0) = v.at(1) = -1;
    }
    return v;
}