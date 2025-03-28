#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ull unsigned long long

ull N, K, chk[101], prime[101], ans, arr[16];
ull gcd(ull a, ull b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}
ull lcm(ull a, ull b) {
    return a*b/gcd(a, b);
}
int main() {
    cin>>N>>K;
    for(int i=0; i<K; i++) cin>>arr[i];
    sort(arr, arr+K);
    for(int i = 1; i<(1<<K); i++) {
        int cnt = 0;
        ull lcmnum = 1;
        for(int j=0; j<K; j++) {
            if(i & (1<<j)) {
                cnt += 1;
                lcmnum = lcm(lcmnum, arr[j]);
            }
        }
        if(cnt%2) ans += N/lcmnum;
        else ans -= N/lcmnum;
    }
    cout<<N-ans;
}