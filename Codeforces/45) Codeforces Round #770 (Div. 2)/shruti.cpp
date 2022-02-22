/* @author -> IUseArchBTW */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n; cin>>m>>n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i=0; i<m; i++){
        int j = 0;
        string s; cin>>s;
        int k = 0;
        while(k < s.size()){
            string t;
            while(k < s.size() && s[k] != ','){
                t.push_back(s[k++]);
            }
            mat[i][j++] = stoi(t);
            k++;
        }
    }
    int sum = 0;
    int ans = 0;
    for(int i=0; i<m; i++){
        if(i%2 == 0){
            for(int j=0; j<n; j++){
                sum += mat[i][j];
                int t = sqrt(sum);
                if(t*t == sum){
                    ans = max(ans, sum);
                    sum = 0;
                }
            }
        }
        else{
            for(int j=n-1; j>=0; j--){
                sum += mat[i][j];
                int t = sqrt(sum);
                if(t*t == sum){
                    ans = max(ans, sum);
                    sum = 0;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}