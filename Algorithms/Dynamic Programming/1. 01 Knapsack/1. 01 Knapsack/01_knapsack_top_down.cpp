#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ts(vector<int> &vec, int t){
    ll n = vec.size();
    vector<pair<ll, ll>> v(n);
    for(ll i=0; i<n; i++){
        v[i].first = vec[i];
        v[i].second = n-i;
    }
    sort(v.begin(), v.end());
    ll i = 0, ans = 0, w = t;
    while(w>0){
        ll c = v[i].first * v[i].second;
        if(c <= w){
            w -= c;
            ans += v[i].second;
        }
        else{
            ans += w/v[i].first;
            w = 0;
        }
        i++;
    }
    return ans;
}


bool equal_sum_partition(vector<int> arr, int sum, int n){
    vector<vector<int>> dp(sum+1, vector<int>(n+1, 0));

    for(int i=0; i<n+1; i++){
        dp[0][i] = 1;
    }
    for(int i=1; i<sum+1; i++){
        dp[i][0] = 0;
    }

    for(int i=1; i<sum+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[j-1]<=i){
                dp[i][j] = (dp[i-arr[j-1]][j-1] || dp[i][j-1]);
            }
            else{
                dp[i][j] = (dp[i][j-1]);
            }
        }
    }
    return dp[sum][n];
}

string solve(vector<int> ar){
    int sum = accumulate(ar.begin(), ar.end(), 0LL), n = ar.size();
    if(!(sum&1) && equal_sum_partition(ar,sum/2,n)){
        return "YES";
    }
    else{
        return "NO";
    }
}


int main(){
    vector<int> v = {1,1,1,1,1,1,6};
    int t = 4;
    // cout<<ts(v, t)<<endl;
    // return 0;
    cout<<solve(v)<<endl;
}