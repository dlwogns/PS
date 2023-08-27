#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int V, M, J, S;
int graph[101][101];
void cal_dist(vector<int>&v, int st){
    priority_queue<pair<int,int>, vector<pair<int,int > > ,greater<pair<int, int> > >pq;
    pq.push(make_pair(0, st));
    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();
        for(int i=1; i<=V; i++){
            if(graph[cur_node][i] == INF) continue;
            int nxt_node = i, nxt_dist = cur_dist + graph[cur_node][i];
            if(v[nxt_node] > nxt_dist){
                pq.push(make_pair(nxt_dist, nxt_node));
                v[nxt_node] = nxt_dist;
            }
        }
    }
}
int main(){
    fastio;
    cin>>V>>M;
    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            graph[i][j] = INF;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a == b) continue;
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }
    cin>>J>>S;
    // 지헌이가 빨리 도착해야됨
    vector<int>distJ(1001, INF);
    vector<int>distS(1001, INF);
    distJ[J] = 0; distS[S] = 0;

    cal_dist(distJ, J); cal_dist(distS, S);
    // check_dist -> 지헌 - 목적지의 거리
    int min_dist = INF;
    for(int i=1; i<=V; i++){
        if(i == J || i == S) continue;
        min_dist = min(min_dist, distJ[i]+distS[i]);
    }
    int ans = INF, check=INF;
    for(int i=1; i<=V; i++){
        if(i == J || i == S) continue;
        if(distJ[i]+distS[i] != min_dist) continue;
        if(distJ[i] > distS[i]) continue;
        if(check > distJ[i]){
            ans = i;
            check = distJ[i];
        }else if(check == distJ[i]){
            ans = min(ans, i);
        }

    }
    (ans == INF) ? cout<<-1 : cout<<ans;
}