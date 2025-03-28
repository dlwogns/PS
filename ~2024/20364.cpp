#include <iostream>
using namespace std;
int N, Q, arr[2000000];
int solve(int a) {
    int ret = 0;
    while(a) {
        if(arr[a]) {
            ret = a;
        }
        a = a>>1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>Q;
    for(int i=0; i<Q; i++){
        int a; cin>>a;
        int ans = solve(a);
        if(ans == 0) {
            arr[a] = 1;
        }
        cout<<ans<<'\n';
    }

}