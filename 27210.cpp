#include <iostream>
using namespace std;
int N, arr[100001], arr2[100001], ans, ans2;
int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        int a; cin>>a;
        if(a == 1) {
            arr[i] = arr[i-1] + 1;
            ans = max(ans, arr[i]);
        }else if(a == 2) {
            arr[i] = arr[i-1] - 1;
            if(arr[i] < 0) arr[i] = 0;
        }

        if(a == 2) {
            arr2[i] = arr2[i-1] + 1;
            ans2 = max(ans2, arr2[i]);
        }else if(a == 1) {
            arr2[i] = arr2[i-1] - 1;
            if(arr2[i] < 0) arr2[i] = 0;
        }
    }
    cout<<max(ans, ans2);
}