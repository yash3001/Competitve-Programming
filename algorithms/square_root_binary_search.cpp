#include<bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int main(){
    int n; cin>>n;
    double upper=n, lower=1.0;
    while(fabs(lower-upper) >= EPS){
        double mid=(lower+upper)/2.0;
        if(mid*mid>=n){
            upper = mid;
        }
        else{
            lower = mid;
        }
    }
    cout<<upper<<endl;
    return 0;
}