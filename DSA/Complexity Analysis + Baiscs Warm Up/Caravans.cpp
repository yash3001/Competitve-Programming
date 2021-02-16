#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n; cin >> n;
	while(n--){
	    long long n; cin >> n;
	    long long arr[n] {0};
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    int low = arr[0], count = 1;
	    for(int i=0; i<n; i++){
	        if(low > arr[i]){
	            count++;
	            low = arr[i];
	        }
	    }
	    cout << count << endl;
	}
	return 0;
}

