#include <iostream>
using namespace std;
long long ans;
int main() {
    long long N, arr[1000001];
    cin>>N;
    for (int i=0; i<N; i++) cin>>arr[i];
    long long B, C; cin>>B>>C;
    for (int i=0; i<N; i++) {
            long long a = (arr[i]-B >= 0) ? ((arr[i]-B)) : 0;
            ans += (a/C + 1);
            if (a%C) ans += 1;
    }
    cout<<ans;
}