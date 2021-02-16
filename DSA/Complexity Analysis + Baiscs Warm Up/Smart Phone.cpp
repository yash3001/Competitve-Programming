#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long n; cin >> n;
	long long arr[n] {};
	for(int i=0; i<n; i++){
	    cin >> arr[i];
	}
	sort(arr, arr+n);
    long long max {}, num = n;
    for(int i=0; i<n; i++){
        if(arr[i]*num > max){
            max = arr[i]*num;
        }
        num--;
    }
    cout << max;
	return 0;
}

