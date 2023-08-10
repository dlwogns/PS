#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int p, w, c, v, ans;
int vis[1001], dist[1001];
vector<vector<pair<int,int>>>graph(1001);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>p>>w>>c>>v;
    for(int i=0; i<w; i++){
        int st, dest, wid;
        cin>>st>>dest>>wid;
        graph[st].push_back({dest, wid});
        graph[dest].push_back({st, wid});
    }
    queue<int>q;
    q.push(c);
    dist[c] = 987654321;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto e : graph[cur]){
            if(dist[e.first] >= min(dist[cur], e.second)) continue;
            dist[e.first] = min(dist[cur], e.second);
            q.push(e.first);
        }
    }
    cout<<dist[v];
}