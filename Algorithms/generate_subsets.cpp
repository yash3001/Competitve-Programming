#include<bits/stdc++.h>

using namespace std;

class superset{
    private:
        int size;
        vector<int> subset;
    public:
        superset (int arg_size) : size(arg_size) {}

        void generate_subsets(int num){
            if(num>size){
                cout<<"( ";
                for(const int &n: subset){
                    cout<<n<<" ";
                }
                cout<<")"<<endl;
            }
            else{
                subset.push_back(num);
                generate_subsets(num+1);
                
                subset.pop_back();
                generate_subsets(num+1);
            }
        }
};

int main(){
    int n; cin>>n;
    superset s(n);
    s.generate_subsets(1);
    return 0;
}