#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void seiveAlg1(int testStart, int testStop){
    // initializing check array which stores 0 if the current number is a prime.
    vector<int> check(testStop-testStart+1, 1);
    for(int i=testStart; i<=testStop; i++){
        if(isPrime(i)){
            check[i-testStart] = 0;
        }
    }
    
    // count all numbers till a prime number is encountered. if count > 5, push into ans.
    vector<vector<int>> ans;
    int count{}, start{};
    for(long unsigned int i=0; i<check.size(); i++){
        if(check[i] == 0){
            if(count>5){
                vector<int> t;
                t.push_back(testStart+start);
                t.push_back(testStart+i-1);
                t.push_back(count);
                ans.push_back(t);
            }
            count = 0;
            start = i+1;
            continue;
        }
        count++;
    }
    //check for the last count
    if(count>5){
        vector<int> t;
        t.push_back(testStart+start);
        t.push_back(testStop);
        t.push_back(count);
        ans.push_back(t);
    }

    //print the answer
    for(const auto &v: ans){
        for(const auto &n: v){
            cout<<n<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int a, b;
    cin>>a>>b;
    seiveAlg1(a, b);
    return 0;
}