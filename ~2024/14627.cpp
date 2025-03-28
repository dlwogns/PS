#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll N, M, arr[1000001], l=1, r=1000000000, ans;
int main() {
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    while(l<=r) {
        ll mid = (l+r)/2;
        if(mid == 0) break;
        ll cnt =0;
        for(ll i=0; i<N; i++)
            cnt += arr[i]/mid;
        if(cnt >= M) l = mid+1;
        else r = mid-1;
    }
    for(int i=0; i<N; i++)
        ans += arr[i];
    cout<<ans - r*M;
}
