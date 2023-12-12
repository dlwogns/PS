#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int V, E, finished[10001], parent;
vector<vector<int > >v(10001);
int dfs(int curnode, int dist, int* vis){
    if(dist != 0 && curnode == parent){
        finished[curnode] = parent;
        return 1;
    }
    
    for(auto e : v[curnode]){
        if(dfs(e, dist+1, vis) == 1)
            finished[curnode] = parent;
    }
    return 0;
}
int main(){
    fastio;
    cin>>V>>E;
    for(int i=0; i<E; i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=1; i<=V; i++){
        int vis[10001] = {0};
        parent = i;
        dfs(i,0, vis);
        for(int i=1; i<=V; i++)
            cout<<finished[i]<<' ';
        cout<<'\n';
    }
    // for(int i=1; i<=V; i++)
    //     cout<<finished[i]<<' ';

}