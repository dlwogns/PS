#include <iostream>
#define fastio cin.tie(0)->cout.tie(0)->sync_with_stdio(0)
#define ll long long
using namespace std;
int N, arr[100001], arr2[10001];
bool verify(int n){
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(sum%arr[i] == 0) ans += 1;
    }
    if(ans != 1) return false;
    return true;
}
int main(){
    cin>>N;
    arr[0] = 2; arr[1] = 3;
    for(int i=2; i<N; i++) arr[i] = arr[i-1]+arr[i-2];
    
    
    //for(int i=0; i<N; i++) cout<<arr[i]<<' ';
    cout<<"test start\n";
    for(int i=0; i<100; i++)
        if(verify(i)) cout<<i<<" true\n";
    cout<<"test end\n";
}
