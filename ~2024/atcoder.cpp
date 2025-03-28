#include <iostream>
using namespace std;
int N, arr[300001], idx[300001], dp[300001], ans;
int main(){
    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>arr[i];
    for(int i=1; i<=N; i++){
        if(idx[arr[i]] == 0) idx[arr[i]] = i;
        else{
            dp[arr[i]] = i-(idx[arr[i]]+1) + dp[arr[i]];
            idx[arr[i]] = i;
        }
        
    }
    for(int i=0; i<=N; i++){
        ans += dp[i];
        cout<<dp[i]<<' ';
    }
    cout<<ans;
    
}