#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> numbers;
	while(true){
	    int n;
	    cin >> n;
	    if(n == 42){
	        break;
	    }
	    numbers.push_back(n);
	}
	for(int i=0; i<numbers.size(); i++){
	    cout << numbers.at(i) << endl;
	}
	return 0;
}
