#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M, graph[501][501], ans;
vector<pair<int,int>>edge;
int main(){
    cout.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            graph[i][j] = INF;
    for(int i=0; i<M; i++){
        int A, B, C;
        cin>>A>>B>>C;
        graph[A][B] = min(graph[A][B],C);
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++){
            if(graph[i][j] != INF) edge.push_back({i,j});
        }
    vector<long long>dist(N+1, INF);
    dist[1] = 0;
    for(int i=1; i<=N; i++)
        for(auto e : edge){
            int cur_node = e.first;
            int nxt_node = e.second;
            int cost = graph[cur_node][nxt_node];
            if(dist[cur_node] == INF) continue;
            if(dist[nxt_node] > dist[cur_node]+cost){
                if(i==N)
                    ans = 1;
                dist[nxt_node] = dist[cur_node]+cost;
            }
        }
    if(ans == 1)
        cout<<-1;
    else{
        for(int i=2; i<=N; i++){
            if(dist[i] == INF) cout<<-1<<'\n';
            else cout<<dist[i]<<'\n';
        }
    }
}