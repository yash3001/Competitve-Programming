// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int t=0;
        while(pow(2, t)<=n){
            t++;
        }
        t--;
        int ans{};
        for(int i=0; i<=t; i++){
                ans+=(((n+1)/int(pow(2, i)))/2)*int(pow(2, i));
                if( ((n+1)/int(pow(2,i)))&1 ){
                    ans+=(n+1)%(int(pow(2,i)));
                }
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends