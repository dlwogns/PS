#include <iostream>
#define fastio cin.tie(0)->cout.tie(0)->sync_with_stdio(0)
#define ll unsigned long long
using namespace std;
ll N, K, arr[500001], cntN;
int main(){
    cin>>N>>K;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    ll lo = 0, hi = 1e12;
    while(lo < hi){
        ll mid = (lo+hi)/2;
        ll check = 0;
        for(int i=0; i<N; i++){
            if(arr[i] > mid) check += arr[i] - mid;
        }
        if(check > K) lo = mid+1;
        else hi = mid;
    }

    cout<<hi;
}
