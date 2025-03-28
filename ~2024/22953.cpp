#include <iostream>
using namespace std;
long long N, K, C, arr[11], ans = 1000000000001;
void solve(int c, int l) {
    if(c == 0) {
        long long lo = 0, hi = 1000000000000;
        while(lo+1 < hi) {
            long long mid = (lo+hi)/2;
            long long check = 0;
            for(int i=0; i<N; i++) {
                check += mid/arr[i];
            }
            if(check >= K) hi = mid;
            else lo = mid;
        }
        ans = min(ans, hi); 
        return;
    }
    for(int i=l; i<N; i++) {
        if(arr[i] == 1) {
            if(i == N-1) solve(0, i);
            continue;
        }
        arr[i] -= 1;
        solve(c-1, i);
        arr[i] += 1;
    }
}
int main() {
    cin>>N>>K>>C;
    for(int i=0; i<N; i++) cin>>arr[i];
    solve(C, 0);
    cout<<ans;
}

//3 6 0
//1 2 3
// 4

