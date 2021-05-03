// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	    // Your code goes here
        for(int i=0; i<s.size()/2; i++){
            if(s.at(i)!=s.at(s.size()-i-1)){
                return 0;
            }
        }
        return 1;
        // string s1 = s;
        // reverse(s1.begin(), s1.end());
        // if(s==s1){
        //     return 1;
        // }
        // return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends