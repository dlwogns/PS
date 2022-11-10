#include <iostream>
using namespace std;
int T, W, arr[1001], rotn[1001][2], dp[1001][30];
int main(){
    cin>>T>>W;
    for(int i=1; i<=T; i++)
        cin>>arr[i];
    for(int i=1; i<=T; i++)
        for(int j=i+1; j<=T; j++){
            if(arr[j] == 1) rotn[i][0] += 1;
            if(arr[j] == 2) rotn[i][1] += 1;
        }
    dp[1][0] = rotn[1][0];
    dp[1][1] = rotn[1][1];
    for(int i=2; i<=T; i++){
        for(int j=0; j<=W; j++){
            if(dp[i-1][j] == 0) continue;
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j])
        }
    }
    
}