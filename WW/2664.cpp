#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        string s, l,r;
        int m;
        cin>>s;
        cin>>m;
        cin>>l>>r;

        int arr[10], count[10][10] = {0};
        for(auto e : s){
            for(int i=0; i<10; i++){
                if(arr[i]){
                    count[i][e-'0'] = 1;
                }
            }
            arr[e-'0'] = 1;
        }
        
        int ans=0;
        for(int i=l[0]-'0'; i <= r[0] - '0'; i++){
            int flag = 0;
            for(int j=1; j<m; j++){
                for(int k = 0; k<10; k++){
                    if(k>=l[j]-'0' && k <=r[j]-'0' && count[i][k] == 0) flag = 1;
                }
                if(!flag) break;
                if(flag && (j == m-1)) continue;
                flag = 0;
            }
            if(flag) ans = 1;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
       

    }
}