/* @author -> IUseArchBTW */
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization.size();
}

int main(){
    string s;
    getline(cin, s);
    int sum = -1;
    int i = 0;
    while(i<s.size()){
        if(s[i] >= '0' && s[i] <= '9'){
            string t;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                t.push_back(s[i++]);
            }
            if(sum == -1){
                sum = 0;
            }
            sum += t[t.size()-1]-'0';
        }
        i++;
    }
    if(sum == -1){
        cout<<-1<<endl;
        return 0;
    }

    if(isPrime(sum)){
        cout<<sum<<endl;
        return 0;
    }

    string t = to_string(sum);
    reverse(t.begin(), t.end());
    sum = stoi(t);

    if(isPrime(sum)){
        cout<<sum<<endl;
        return 0;
    }

    cout<<trial_division1(sum)+2<<endl;

    return 0;
}