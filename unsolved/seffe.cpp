#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T, arr[100001];
void cycle(int st, int dest, int* ans, int* d){
    if(st == dest){
        ans[st] = 1;
        d[st] = 1;
        return;
    }
    ans[st] = 1;
    d[st] = 1;
    cycle(arr[st], dest, ans, d);
}
void dfs(int pre, int n, int* vis, int* ans, int* d){
    if(vis[n]){
        //cycle
        cycle(n, pre, ans, d);
        return;
    }
    vis[n] = 1;
    d[n] = 1;
    dfs(n, arr[n], vis, ans, d);
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        int N, ans[100001]={0}, ans_num=0, d[100001]={0};
        cin>>N;
        // for(int i=1; i<=N; i++){
        //     cin>>arr[i];
        //     ans[i] = -1;
        // }
        for(int i=1; i<=N; i++){
            if(d[i]) continue;
            int vis[100001]={0};
            dfs(i, arr[i], vis, ans, d);
            // cout<<endl<<i<<endl;
            // for(int i=1; i<=N; i++)
            //     cout<<ans[i]<<' ';
            // cout<<endl;
        }
        
        for(int i=1; i<=N; i++)
            if(ans[i] == 1) ans_num += 1;
        cout<<N-ans_num<<'\n';
    }
}