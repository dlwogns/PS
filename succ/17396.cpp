#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 100000000000
using namespace std;
int N, M, seen[100001], vis[100001];
vector<vector<pair<int,int>>>graph(100001);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>seen[i];
    for(int i=0; i<M; i++){
        int a, b, t;
        cin>>a>>b>>t;
        if((seen[a] || seen[b]) && a!=N-1 && b != N-1) continue;
        graph[a].push_back({t, b});
        graph[b].push_back({t, a});
    }
    for(int i=0; i<N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    vector<long long>dist(N, INF);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<>>pq;
    pq.push({0,0});
    dist[0] = 0;
    while(!pq.empty()){
        long long cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if(vis[cur_node]) continue;
        vis[cur_node] = 1;
        if(cur_node == N-1) break;
        for(int i=0; i<graph[cur_node].size(); i++){
            int nxt_node = graph[cur_node][i].second;
            if(seen[nxt_node] && nxt_node != N-1) continue;
            long long nxt_dist = cur_dist + graph[cur_node][i].first;
            if(nxt_dist < dist[nxt_node]){
                dist[nxt_node] = nxt_dist;
                if(!vis[nxt_node])
                    pq.push({nxt_dist, nxt_node});
            }
        }
    }
    if(dist[N-1] == INF) 
        cout<<-1;
    else
        cout<<dist[N-1];
    
}