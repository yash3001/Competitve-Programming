#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    static bool mycomp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second==b.second)
        return a.second<b.second;
        else
        return a.second>b.second;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
            m[arr[i]]++;
        vector<pair<int,int>>v;
        for(auto x:m)
        v.push_back(make_pair(x.first,x.second));
        sort(v.begin(),v.end(),mycomp);
        vector<int>v1;
        for(auto x:v)
        {
            for(int i=0; i<x.second; i++)
                v1.push_back(x.first);
        }
        return v1;
    }
};
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Solution obj;
    vector<int>v=obj.sortByFreq(arr,n);
    for(auto x:v)
    cout<<x<<" ";
}