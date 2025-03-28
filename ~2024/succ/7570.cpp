#include <iostream>
using namespace std;
int N, arr[1000001],dp[1000001], ans;
int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    for(int i=0; i<N; i++){
        dp[arr[i]] = dp[arr[i]-1]+1;
        ans = max(ans, dp[arr[i]]);
    }
    cout<<N-ans;

}