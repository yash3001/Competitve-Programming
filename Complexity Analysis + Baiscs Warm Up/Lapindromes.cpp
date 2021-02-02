#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    long length = s.length();
	    int left[26] {};
	    int right[26] {};
	    int z[26] {};
	    for(int i=0; i<length/2; i++){
	        left[s[i]-'a']++;
	    }
	    for(int i=(length+1)/2; i<length; i++){
	        right[s[i]-'a']++;
	    }
	    int flag {};
	    for(int i=0; i<26; i++){
	        if(left[i] != right[i]){
	            flag = 1;
	        }
	    }
	    if (flag){
	        cout << "NO" << endl;
	    }
	    else{
	        cout << "YES" << endl;
	    }
	}
	return 0;
}

