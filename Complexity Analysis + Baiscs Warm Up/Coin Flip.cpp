#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    long long g; cin>>g;
	    while(g--){
	        int i, q; long long n;
	        cin >> i >> n >> q;
	       // long long coins[n];
	       // for(int i=0; i<n; i++){
	       //     coins[i] = i;
	       // }
	        long long ans {};
	        if(i==q){
	            ans = n/2;
	        }
	        else{
	           ans = n - (n/2);
	        }
	        cout<<ans<<endl;
	    }
	}
	return 0;
}

