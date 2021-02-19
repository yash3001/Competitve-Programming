#include<iostream>

using namespace std;

template <typename T>
void swapll(T &a, T &b){
    a = a^b;
    b = b^a;
    a = a^b;
}

int main(){
    long long a, b; cin>>a>>b;
    // swapll<long long>(a,b);
    swapll(a,b);
    cout<<"a="<<a<<" b="<<b<<endl;
    return 0;
}