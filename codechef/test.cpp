// #include <iomanip>
// #include<iostream>

// using namespace std;

// int main(){
//     // int x; cin >> x;
//     // float y; cin >> y;
//     // if(x%5==0 && x+0.5<=y)
//     //     y-=x+0.5;
//     // cout << setprecision(2) << fixed << y << endl;
//     int arr[10]{};
//     for(const int &i: arr){
//         cout<<i<<endl;
//     }
//     cout << sizeof(arr)/sizeof(int) << endl;
//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

template <typename T>
void print(set<T> &s){
    for(auto i=s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(const auto &i: s){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    set<int> s;
    print<int>(s);
    auto check = s.insert(12);
    check = s.insert(4);
    check = s.insert(1);
    check = s.insert(2);
    check = s.insert(12);
    print(s);
    s.clear();
    cout<<s.max_size()<<" "<<s.empty()<<endl;
    return 0;
}