#include <iostream>
using namespace std;
long long T, arr[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int chk = 0, cnt = 1;
    for(int i=1; i<=63245; i++) {
        arr[i] = cnt + arr[i-1];
        chk += 1;
        if(chk == 2) {
            chk = 0; cnt += 1;
        }
    }
    
    cin>>T;
    while(T--) {
        int N; cin>>N;
        int lo = 0, hi = 63245;
        while(lo+1 < hi) {
            int mid = (lo+hi)/2;
            if(arr[mid] >= N) hi = mid;
            else lo = mid;
        }
        cout<<4+lo*2<<"\n";
    }
}