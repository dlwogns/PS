#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N,M, arr[101][2], dp[10000001], cparr[10000001];
int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        cin>>arr[i][0];
    for(int i=1; i<=N; i++)
        cin>>arr[i][1];
    for(int i=0; i<=M; i++)
        dp[i] = INF;
    int sum_m = 0;
    for(int i=1; i<=N; i++){
        sum_m += arr[i][0];
        for(int j=1; j<=sum_m; j++){
            cparr[j] = dp[j];
            if(j > 10000000) break;
            if(j <= arr[i][0]) dp[j] = min(cparr[j], arr[i][1]);
            else dp[j] = min(cparr[j-arr[i][0]]+arr[i][1], cparr[j]);
        }
    }
    cout<<dp[M];
    
}