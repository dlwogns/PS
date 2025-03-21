#include <iostream>
using namespace std;
int N;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N;
    while(N--) {
        int a; cin>>a; 
        long long ans=0;
        while(a) {
            ans += a/5;
            a /= 5;
        }
        cout<<ans<<'\n';
    }
}