#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;
int N, arr[501], num[2000001], check[501], ans = 1000;
int main(){
    fastio;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        num[arr[i]] += 1;
    }
    for(int i=0; i<2e6+1; i++){
        if(num[i] >= N>>2) ans = min(ans, N-num[i]);
    }

    for(int i=1; i<=N; i++){
        if(arr[i] > arr[i-1]) check[i] = 1;
        if(arr[i] < arr[i-1]) check[i] = 2;
        cout<<check[i]<<' ';
    }
    

}
