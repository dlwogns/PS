#include <iostream>
#include <sys/types.h>
#define INF 1000000001
using namespace std;
long long N,W, arr[101][2], dp[101][100001], ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>N>>W;
	for(int i=1; i<=N; i++){
		cin>>arr[i][0]>>arr[i][1];
	}
	for(int i=0; i<=N; i++)
		for(int j=0; j<=100000; j++)
			dp[i][j] = INF;
	int sum = 0;
	for(int i=1; i<=N; i++){
		sum += arr[i][1];
		for(int v=1; v<=sum; v++){
			if(arr[i][1] >= v) dp[i][v] = min(dp[i-1][v], arr[i][0]);
			else{
				dp[i][v] = min(dp[i-1][v], arr[i][0]+dp[i-1][v-arr[i][1]]);
			}
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<= sum; j++){
			if(dp[i][j] >= INF) continue;
			if(dp[i][j] <= W && j > ans) ans = j;
		}
	}
	cout<<ans;

}