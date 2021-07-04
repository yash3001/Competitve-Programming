/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

string binString(int val){
    string s;
    while(val>0){
        if(val&1){
            s = '1' + s;
        }
        else{
            s = '0' + s;
        }
        val >>= 1;
    }
    return s;
}

int binToDec(string s){
    int ans = 0;
    int base = 1;

    for(int i=s.size()-1; i>=0; i--){
        ans += (s.at(i)-'0')*base;
        base *= 2;
    }

    return ans;
}

int toHex(int val){
    string s = binString(val);
    
    int i;
    for(i=s.size()-1; i>=0; i--){
        if(s.at(i) == '1'){
            break;
        }
    }
    if(i == -1){
        s = '1'+s;
    }
    else{
        for(int j=i-1; j>=0; j--){
            if(s.at(j) == '0'){
                s.at(j) = '1';
            }
            else{
                s.at(j) = '0';
            }
        }
    }

    cout<<"\nBinary equivalent to 2's complement of "<<val<<": "<<s<<endl;

    return binToDec(s);    
}

int main(){
    cout<<"Enter the decimal value: ";
    int n; cin>>n;
    int ans = toHex(n);
    cout<<"Decimal equivalent of 2's complement of "<<n<<": "<<ans<<endl;
    return 0;
}