#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define INF 987654321
vector< vector<pair<double,int> > > graph(4001);
// 달빛 여우와 늑대는 1번 노드에서 시작 -> 다익스트라
int N, M, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int a, b, d;
        cin>>a>>b>>d;
        graph[a].push_back(make_pair(d, b));
        graph[b].push_back(make_pair(d, a));
    }
    for(int i=1; i<=N; i++)
        sort(graph[i].begin(), graph[i].end());

    vector<int>dist_fox(4001, INF);
    vector<double>dist_wolf(4001, INF);
    dist_fox[1] = 0;
    dist_wolf[1] = 0;

    //fox
    priority_queue<pair<int,int>, vector<pair<int,int> > >pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();
        for(auto e : graph[cur_node]){
            int nxt_node = e.second;
            int nxt_dist = cur_dist + e.first;
            if(dist_fox[nxt_node] > nxt_dist){
                dist_fox[nxt_node] = nxt_dist;
                pq.push(make_pair(nxt_dist, nxt_node));
            }
        }
    }

    priority_queue<pair<double,pair<int,int> >, vector<pair<double,pair<int,int> > > >pq2;
    pq2.push(make_pair(0, make_pair(1, 1)));
    dist_wolf[1] = 0;
    while(!pq2.empty()){
        int cur_node = pq2.top().second.first;
        double cur_dist = pq2.top().first;
        int check = pq2.top().second.second;
        pq2.pop();
        for(auto e : graph[cur_node]){
            int nxt_node = e.second;
            double nxt_dist;
            if(check)
                nxt_dist = cur_dist + e.first/2;
            else
                nxt_dist = cur_dist + e.first * 2;
            if(dist_wolf[nxt_node] > nxt_dist){
                dist_wolf[nxt_node] = nxt_dist;
                if(check)
                    pq2.push(make_pair(nxt_dist, make_pair(nxt_node, 0)));
                else
                    pq2.push(make_pair(nxt_dist, make_pair(nxt_node, 1)));
            }
        }
    }

    //wolf
    for(int i=2; i<=N; i++){
    priority_queue<pair<double,pair<int,int> >, vector<pair<double,pair<int,int> > > >pq3;
    pq3.push(make_pair(0, make_pair(i, 1)));
    vector<double>dist_wolf_v(4001, INF);
    dist_wolf_v[i] = 0;
    while(!pq2.empty()){
        int cur_node = pq3.top().second.first;
        double cur_dist = pq3.top().first;
        int check = pq3.top().second.second;
        pq3.pop();
        for(auto e : graph[cur_node]){
            int nxt_node = e.second;
            double nxt_dist;
            if(check)
                nxt_dist = cur_dist + e.first/2;
            else
                nxt_dist = cur_dist + e.first * 2;
            if(dist_wolf_v[nxt_node] > nxt_dist){
                dist_wolf_v[nxt_node] = nxt_dist;
                if(check)
                    pq3.push(make_pair(nxt_dist, make_pair(nxt_node, 0)));
                else
                    pq3.push(make_pair(nxt_dist, make_pair(nxt_node, 1)));
            }
        }
    }
    if(dist_wolf[i] > dist_wolf_v[1])
        dist_wolf[i] = dist_wolf_v[1];
    }

    for(int i=1; i<=N; i++){
        if(dist_fox[i] < dist_wolf[i])
            ans += 1;
    }
    cout<<ans;


    
}