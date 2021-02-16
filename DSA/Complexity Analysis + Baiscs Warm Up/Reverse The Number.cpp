#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int cases {};
	cin >> cases;
	while(cases--){
	    long long int num {};
	    cin >> num;
	    long long int ans {};
	    while(num != 0){
	        ans = ans*10 + num%10;
	        num /= 10;
	    }
	    cout << ans << endl;
	}
	return 0;
}

