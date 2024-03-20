#include <iostream>
using namespace std;
long long N, K, arr[201];
long long ans;
int main(){
    cin>>N>>K;
    arr[K] = 1;
    for(int i=K+1; i<=N; i++){
        for(int j=1; j<i; j++){
            arr[i] += (arr[i-j]*K)%1000000000;
        }
    }
    cout<<arr[N];

}

// 4 4 -> 1
// 5 4 -> 