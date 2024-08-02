#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[1001], ans;
int main() {
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>arr[i];
    sort(arr, arr+N);
    int banker = 0;
    for(int i=N-1; i>=banker; i--) {
        if(arr[i] > 0) {
            ans += arr[i];
            banker += 1;
        }
        if(i == N-M) break;
    }
    cout<<ans;
        
}
