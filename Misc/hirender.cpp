/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

class Relation{
    int r, c, n;
    int mat[1001][1001];
    int set[1001];
    public:
        void initMatrix(){
            // cout<<"Enter the number of rows(max 1000): ";
            // cin>>r;
            // cout<<"Enter the number of columns(max 1000): ";
            // cin>>c;
            // cout<<"Enter the matrix:"<<endl;
            // for(int i=0; i<r; i++){
            //     for(int j=0; j<c; j++){
            //         cin>>mat[i][j];
            //     }
            // }
            memset(mat, 0, sizeof(mat));
            cout<<"Enter the size of the set: ";
            cin>>n;
            cout<<"Enter the members of the set: ";
            unordered_map<int, int> mp;
            for(int i=0; i<n; i++){
                cin>>set[i];
                mp[set[i]] = i;
            }
            r=c=n;
            char y='y';
            do{
                cout<<"Enter the ordered pair: ";
                int o1, o2; cin>>o1>>o2;
                mat[mp[o1]][mp[o2]] = 1;
                cout<<"Enter y if you want to enter another ordered pair: ";
                cin>>y;
            }while(y=='y'||y=='Y');
            cout<<"The set is:\n";
            for(int i=0; i<n; i++){
                cout<<set[i]<<" ";
            }
            cout<<"\nThe matrix is:\n";
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        bool isReflexive(){
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
    char y;
    do{
        cout<<"\n\n____________________MENU___________________"<<endl;
        cout<<"1) CHECK WHETHER RELATION IS REFLEXIVE"<<endl;
        cout<<"2) CHECK WHETHER RELATION IS SYMMETRIC"<<endl;
        cout<<"3) CHECK WHETHER RELATION IS ANTISYMMETRIC"<<endl;
        cout<<"4) CHECK WHETHER RELATION IS TRANSITIVE"<<endl;
        cout<<"5) CHECK WHETHER RELATION IS EQUIVALENT"<<endl;
        cout<<"6) CHECK WHETHER RELATION IS PARTIAL ORDER RELATION"<<endl;
        cout<<"7) EXIT"<<endl;
        cout<<"\nEnter your choice: ";
        int choice; cin>>choice;
        switch(choice){
            case 1:
                if(test.isReflexive()){
                    cout<<"\nYes, the relation is reflexive"<<endl;
                }
                else{
                    cout<<"\nNo, the relation is not reflexive"<<endl;
                }
                break;
            case 2:
                if(test.isSymmetrix()){
                    cout<<"\nYes, the relation is symmetric"<<endl;
                }
                else{
                    cout<<"\nNo, the relation is not symmetric"<<endl;
                }
                break;
            case 3:
                if(test.isAntiSymmetric()){
                    cout<<"\nYes, the relation is antisymmetric"<<endl;
                }
                else{
                    cout<<"\nNo, the relation is not antisymmetric"<<endl;
                }
                break;
            case 4:
                if(test.isTransitive()){
                    cout<<"\nYes, the relation is transitive"<<endl;
                }
                else{
                    cout<<"\nNo, the relation is not transitive"<<endl;
                }
                break;
            case 5:
                if(test.isReflexive() && test.isSymmetrix() && test.isTransitive()){
                   cout<<"\nYes, the given relation is equivalence"<<endl;
                }
                else{
                   cout<<"\nNo, the given relation is not an equivalence"<<endl;
                }
                break;
            case 6:
                if(test.isReflexive() && test.isAntiSymmetric() && test.isTransitive()){
                    cout<<"\nYes, the given relation is partial order"<<endl;
                }
                else{
                    cout<<"\nNo, the given relation is not a partial order"<<endl;
                }
                break;
            case 7:
                return 0;
            default:
                cout<<"\nWrong input, please try again."<<endl;
        }
        cout<<"\nDo you want to repeat an operation Y/N: ";
        cin>>y;
    }while(y=='y'||y=='Y');
    // if(test.isReflexive() && test.isSymmetrix() && test.isTransitive()){
    //     cout<<"The given relation is equivalence"<<endl;
    // }
    // else if(test.isReflexive() && test.isAntiSymmetric() && test.isTransitive()){
    //     cout<<"The given relation is partial order"<<endl;
    // }
    // else{
    //     cout<<"The given relation is neither an equivalence nor a partial order";
    // }
    return 0;
}