#include <iostream>
using namespace std;
int T, N;
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        int arr[100001][2]={0}, dp[100001][2]={0};
        for(int i=1; i<=N; i++)
            cin>>arr[i][0];
        for(int i=1; i<=N; i++)
            cin>>arr[i][1];
        for(int i=1; i<=N; i++){
            dp[i][0] = max(dp[i-1][1]+arr[i][0], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]+arr[i][1], dp[i-1][1]);
        }
        int ans = max(dp[N][0], dp[N][1]);
        cout<<ans<<'\n';
    }
}