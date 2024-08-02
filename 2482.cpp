#include <iostream>
#define ll long long
#define MODNUM 1000000003
using namespace std;
ll N, K, dp[1001][1001];
int main() {
    cin>>N>>K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            if(i == j) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MODNUM;
            }
        }
    cout<<(dp[N-K][K]*2 + dp[N-K][K+1])%MODNUM;
}