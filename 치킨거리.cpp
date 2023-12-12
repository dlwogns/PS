#include <iostream>
#define MAX_INT 1000000000000
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int T;
int main(){
    fastio;
    cin>>T;
    while(T--){
        long long N, arr[501], dp[501][501]={0}, sum[501] = {0};
        cin>>N;
        for(int i=1; i<=N; i++){
            cin>>arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N-i; j++){
                long long a = j, b = j+i;
                    dp[a][b] = MAX_INT;
                    for(int k=a; k<b; k++){
                        dp[a][b] = min(dp[a][b], dp[a][k]+dp[k+1][b]+sum[b]-sum[a-1]);
                    }
                
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++)
                cout<<dp[i][j]<<' ';
            cout<<endl;
        }
        cout<<dp[1][N]<<'\n';
        
    }
}