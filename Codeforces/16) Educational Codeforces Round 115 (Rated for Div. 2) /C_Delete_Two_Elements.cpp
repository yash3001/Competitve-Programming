/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> nums(n);
        long long sum = 0;
        unordered_map<double, long long> mp;
        for(int i=0; i<n; i++){
            cin>>nums[i];
            sum += nums[i];
        }
        double mean = double(sum)/n;
        double req = sum-double(mean)*(n-2);
        long long ans = 0;
        for(long long i=0; i<n; i++){
            double a = nums[i];
            double b = req - a;
            ans += mp[b];
            mp[nums[i]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}