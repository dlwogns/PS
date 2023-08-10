#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1000000001
using namespace std;
int T;
int main(){
    fastio;
    cin>>T;
    while(T--){
        int K, arr[501], dp[501][501];
        cin>>K;
        for(int i=1; i<=K; i++){
            cin>>arr[i];
            arr[i] += arr[i-1];
        }
        for(int i=1; i<=K; i++)
            for(int j=1; j<=K-i; j++){
                dp[j][i+j] = INF;
            }
        


    }
}