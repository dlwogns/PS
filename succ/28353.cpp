#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int N, K, arr[5001], check[5001], ans;
int main(){
    fastio;
    cin>>N>>K;
    for(int i=0; i<N; i++)  cin>>arr[i];
    sort(arr, arr+N);
    for(int i=N-1; i>=0; i--)
        for(int j=i-1; j>=0; j--){
            if(i == j) continue;
            if(check[i] || check[j]) continue;
            if(arr[i]+arr[j] <= K){
                check[i] = 1;
                check[j] = 1;
                ans += 1;
            }
        }
    cout<<ans;
}
