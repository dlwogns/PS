#include <iostream>
using namespace std;
int N, arr[200001], check[200001];
long long ans;
int main() {
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    for(int i=1; i<N; i++)
        if(arr[i] > arr[i-1])
            check[i] = 1;
    long long len = 0;
    for(int i=1; i<N; i++){
        if(check[i]) {
            len += 1;
            continue;
        }
        ans += (len+1) * (len) / 2;
        len = 0;
    }
    

    cout<<(len+1) * len / 2 + ans + N;
}