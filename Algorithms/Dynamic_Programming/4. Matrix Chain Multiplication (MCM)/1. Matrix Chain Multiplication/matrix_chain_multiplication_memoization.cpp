/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int matrix_chain_multiplication(vector<int> &arr, int i, int j);

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the size of the multiplication array: ";
    int n; cin>>n;
    cout<<"Enter the matrix multiplication array: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Minimum multiplicaton cost is "<<matrix_chain_multiplication(arr, 1, arr.size()-1)<<endl;
    return 0;
}


int matrix_chain_multiplication(vector<int> &arr, int i, int j){
    if(i>=j){
        return dp[i][j]=0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int min=INT_MAX;
    for(int k=i; k<j; k++){
        int temp =  matrix_chain_multiplication(arr, i, k)+matrix_chain_multiplication(arr, k+1, j)+arr[i-1]*arr[k]*arr[j];
        if(temp<min){
            min = temp;
        }
    }
    return dp[i][j]=min;
}