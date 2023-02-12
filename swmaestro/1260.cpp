#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, V;
int vis1[1001], vis2[1001];
vector<vector<int> >v(1001);
void dfs(int n, int* vis){
    if(vis[n]) return;
    vis[n] = 1;
    cout<<n<<' ';
    for(auto e : v[n])
        dfs(e, vis);
    return;
}
int main(){
    cin>>N>>M>>V;
    for(int i=0; i<M; i++){
        int st, dest;
        cin>>st>>dest;
        v[st].push_back(dest);
        v[dest].push_back(st);
    }

    for(int i=0; i<=N; i++)
        sort(v[i].begin(), v[i].end(), less<int>());
    dfs(V, vis1);
    cout<<'\n'; 
    queue<int>q;
    q.push(V);
    vis2[V] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<' ';
        for(auto e : v[cur]){
            if(vis2[e]) continue;
            q.push(e);
            vis2[e] = 1;
        }
    }
    
}