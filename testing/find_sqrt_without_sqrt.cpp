#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    double lo=1.0, hi=n;
    while(hi-lo>0){
        double mid = (hi+lo)/2.0;
        if(mid*mid >= n){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    cout << lo << endl;
    return 0;
}