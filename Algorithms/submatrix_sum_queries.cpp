/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number of rows and columns: ";
    int r, c; cin>>r>>c;
    int mat[r][c];
    cout<<"Enter the matrix:"<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>mat[i][j];
        }
    }
    int aux[r][c];
    for(int j=0; j<c; j++){
        aux[0][j] = mat[0][j];
    }
    for(int j=0; j<c; j++){
        for(int i=1; i<r; i++){
            aux[i][j] = mat[i][j]+aux[i-1][j];
        }
    }
    for(int i=0; i<r; i++){
        for(int j=1; j<c; j++){
            aux[i][j] = aux[i][j-1]+aux[i][j];
        }
    }
    cout<<"\nOriginal Matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nAuxilary Matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<aux[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}