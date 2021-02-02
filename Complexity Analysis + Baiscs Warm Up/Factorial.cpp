#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long n; cin >> n;
	while(n--){
	    long long num; cin >> num;
	    long long count {};
	    while(num>0){
	        count += num/5;
	        num /= 5;
	    }
	    cout << count << endl;
	}
	return 0;
}

