/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int n, ct=0;
int col[1001];
int diagonal1[1001];
int diagonal2[1001];

void nqueen(int r){
    if(r == n){
        ct++;
    }
    else{
        for(int c=0; c<n; c++){
            if(col[c] || diagonal1[c+r] || diagonal2[c-r+n-1]){
                continue;
            }
            col[c] = diagonal1[c+r] = diagonal2[c-r+n-1] = 1;
            nqueen(r+1);
            col[c] = diagonal1[c+r] = diagonal2[c-r+n-1] = 0;
        }
    }
}

int main(){
    memset(col, 0, sizeof(col));
    memset(diagonal1, 0, sizeof(diagonal1));
    memset(diagonal2, 0, sizeof(diagonal2));

    cin>>n;
    nqueen(0);
    cout<<ct<<endl;
    return 0;
}