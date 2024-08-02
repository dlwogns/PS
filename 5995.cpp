#include <iostream>
#include <algorithm>
using namespace std;
int H, N, arr[501], dp[501][45001];
int main() {
    cin>>H>>N;
    for(int i=1; i<=N; i++) {
        cin>>arr[i];
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=H; j++) {
            if(j>=arr[i])
                dp[i][j] = max(dp[i-1][j], dp[i][j-arr[i]]+arr[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[N][H];
}

//    15 19 20 21 34 35 36
//15  15 15 15 15 15 15 15
//19  15 19 19 19 34 34 34
//20  15 19 20 20 20 35 35
//21  15 19 21 
