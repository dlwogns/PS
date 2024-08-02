#include <iostream>
#include <algorithm>
using namespace std;
long long N, A, B, arr[101][5],dp[101][5][101][101][2], ans;
int main() {
    cin>>N>>A>>B;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=4; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=4; j++) {
            for(int k=0; k<=B; k++) {
                for(int l=0; l<A; l++) {
                    for(int o=0; o<2; o++) {
                        if(j == 1 || j == 2) {
                            long long c1 = max(dp[i-1][1][k][l][o], dp[i-1][2][k][l][o]);
                            dp[i][j][k+1][l][o] = c1 + arr[i][j];
                            if(B == k) {
                                ans = max(ans, dp[i][j][k+1][l][o]);
                            }

                            long long c2 = 0;
                            if(k) c2 = max(dp[i-1][3][k-1][l][o], dp[i-1][4][k-1][l][o]);
                            dp[i][j][k][l][o] = c2 + arr[i][j];
                            if(k>=B) ans = max(ans, dp[i][j][k][l][o]);
                            
                        } else if(j == 3) {
                            if(o) {
                                dp[i][j][k][l][o] = dp[i-1][j][k][l][o-1] + arr[i][j];
                                if(k>=B) ans = max(ans, dp[i][j][k][l][o]);
                                continue;
                            }
                            long long c1 = max(dp[i-1][1][k][l][o], dp[i-1][2][k][l][0]);
                            long long c2 = max(c1, dp[i-1][4][k][l][o]);
                            dp[i][j][k][l][o+1] = c2 + arr[i][j];
                            if(k>=B) ans = max(ans, dp[i][j][k][l][o+1]);
                        }else if(j == 4) {
                            if(l >= A) continue;
                            long long c1 = max(dp[i-1][1][k][l][o], dp[i-1][2][k][l][o]);
                            long long c2 = max(dp[i-1][3][k][l][o], dp[i-1][4][k][l][o]);
                            dp[i][j][k][l+1][o] = max(c1, c2) + arr[i][j];
                            if(k>=B) ans = max(ans, dp[i][j][k][l+1][o]);
                        }
                        if(ans == 171) 
                        {
                            cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<o<<endl;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;


}
