#include <iostream>
using namespace std;
int T, W, arr[1001], dp[1001][31], ans;
int main(){
    cin>>T>>W;
    for(int i=1; i<=T; i++)
        cin>>arr[i];
    for(int i=1; i<=T; i++){
        for(int j=0; j<=W; j++){
            if(j == 0){
                if(arr[i] == 1)
                    dp[i][j] = dp[i-1][j]+1;
                else 
                    dp[i][j] = dp[i-1][j];
                continue;
            }
            if(j % 2 == 1){
                if(arr[i] == 2)
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i-1][j]+1);
                else
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
                
            }else{
                if(arr[i] == 1)
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i-1][j]+1);
                else
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    for(int i=0; i<=W; i++){
        ans = max(ans, dp[T][i]);
    }
    cout<<ans;
}