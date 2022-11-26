#include <iostream>
using namespace std;
int cnt[51], N, ans;
void func(int idx, int n, int check){
    if(idx > N){
        ans = max(ans, n);
        return;
    }
    if(cnt[idx] == 1){
        func(idx+1, n+1, 1);
        func(idx+1, 0, 0);
    }else{
        if(check) func(idx+1, n+1, 1);
        else func(idx+1, n+2, 0);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>cnt[i];
    func(1,0,0);
    cout<<ans;
}