/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int rod_cutting(vector<int> &length, vector<int> &value, int w, int n);

int main(){
    cout<<"Enter the lenght of the rod: ";
    int l; cin>>l;
    int n; n=l;
    vector<int> value(n), length(n);
    cout<<"Enter the weight of the elements:"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter value for length "<<i+1<<" of rod: ";
        cin>>value[i];
    }
    for(int i=1; i<=l; i++){
        length.at(i-1) = i;
    }
    cout<<"The maximum profit is: "<<rod_cutting(length, value, l, n)<<endl;
    return 0;
}

int rod_cutting(vector<int> &length, vector<int> &value, int l, int n){
    if(n==0 || l==0){
        return 0;
    }
    if(length[n-1]<=l){
        return max(value[n-1] + rod_cutting(length, value, l-length[n-1], n), rod_cutting(length, value, l, n-1));
    }
    else{
        return rod_cutting(length, value, l, n-1);
    }
}