#include <iostream>
using namespace std;

int N, M, J, ans;
int main() {
    cin>>N>>M>>J;
    int l = 1, r = M;
    while(J--) {
        int p; cin>>p;
        if(p >= l && p <= r) continue;
        if(p > r) {
            l += p-r; ans += p-r; r = p;
        }else if( p < l) {
            r -= l-p; ans += l-p; l = p;
        }
    }
    cout<<ans;

}