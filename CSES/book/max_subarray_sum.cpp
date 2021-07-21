/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum{}, best{};
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            best = max(best, sum);
        }
    }
    cout<<best<<endl;

    sum = 0, best = 0;
    for(int k=0; k<n; k++){
        sum = max(arr[k], sum+arr[k]);
        best = max(best, sum);
    }
    cout<<best<<endl;
    return 0;
}