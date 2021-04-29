/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

class Relation{
    int r, c;
    int mat[1001][1001];
    public:
        void initMatrix(){
            cout<<"Enter the number of rows(max 1000): ";
            cin>>r;
            cout<<"Enter the number of columns(max 1000): ";
            cin>>c;
            cout<<"Enter the matrix:"<<endl;
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cin>>mat[i][j];
                }
            }
        }

        bool ifReflexive(){
            if(r != c){
                return false;
            }
            bool check{true};
            for(int i=0; i<r; i++){
                if(mat[i][i] != 1){
                    check = false;
                    break;
                }
            }
            return check;
        }

        bool isSymmetrix(){
            if(r != c){
                return false;
            }
            bool check{true};
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(mat[i][j] != mat[j][i]){
                        check = false;
                        break;
                    }
                }
            }
            return check;
        }

        bool isAntiSymmetric(){
            if(r != c){
                return false;
            }
            bool check{true};
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(mat[i][j] == mat[j][i] && i!=j){
                        check = false;
                        break;
                    }
                }
            }
            return check;
        }

        bool isTransitive(){
            if(r!=c){
                return false;
            }
            bool check{true};
            int sq_mat[r][c];
            memset(sq_mat, 0, sizeof(sq_mat));
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    for(int k=0; k<c; k++){
                        sq_mat[i][j] += mat[i][k]*mat[k][j];
                    }
                }
            }
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(sq_mat[i][j] != 0 && mat[i][j]==0){
                        check = false;
                        break;
                    }
                }
            }
            return check;
        }

};

int main(){
    Relation test;
    test.initMatrix();
    if(test.ifReflexive() && test.isSymmetrix() && test.isTransitive()){
        cout<<"The given relation is equivalence"<<endl;
    }
    else if(test.ifReflexive() && test.isAntiSymmetric() && test.isTransitive()){
        cout<<"The given relation is partial order"<<endl;
    }
    else{
        cout<<"The given relation is neither an equivalence nor a partial order";
    }
    return 0;
}