// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<char> v;
		    unordered_map<char, int> mp;
		    char curr;
		    int i=-1;
		    string ans;
		    for(const auto &c: A){
		        if(!mp[c]){
		            if(i == -1){
		                i++;
		                curr = c;
		                ans.push_back(c);
		            }
		            else{
		                if(i != v.size()){
		                    ans.push_back(v.at(i));
		                }
		                else{
		                    curr = c;
		                    ans.push_back(curr);
		                }
		            }
		            mp[c]++;
		            v.push_back(c);
		        }
		        
		        else{
		            mp[c]++;
		            if(c != curr){
		                if(i != v.size())
		                    ans.push_back(v.at(i));
		                else{
		                    ans.push_back('#');       
		                }
		            }
		            else{
		                i++;
		                while(i < v.size()){
		                    if(mp[v.at(i)] == 1){
		                        curr = v.at(i);
		                        break;
		                    }
		                    i++;
		                }
		                
		                if(i == v.size()){
		                    ans.push_back('#');
		                    curr = ' ';
		                }
		                else{
		                    ans.push_back(v.at(i));
		                }
		            }
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends