#include <iostream>
using namespace std;
int N;
long long ans[1001];
int main(){
    cin>>N;
    ans[1] = 1;
    ans[2] = 2;
    for(int i=3; i<=N; i++){
        ans[i] = ans[i-1] + ans[i-2];
        ans[i] %= 10007;
    }
    cout<<ans[N]%10007;
}