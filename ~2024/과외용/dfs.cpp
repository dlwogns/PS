#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, V;
int vis1[1001], vis2[1001];
vector<vector<int>>graph(1001);
void dfs(int node, int* vis){
    if(vis[node]) return; // backtracking
    vis[node] = 1;
    cout<<node<<' ';
    for(auto e : graph[node]){
        dfs(e, vis);
    }
    return;
}
// 1 2
// 1 3
// graph[1] = {2, 3}

int main(){
    cin>>N>>M>>V;
    for(int i=0; i<M; i++){
        int st, dest;
        cin>>st>>dest;
        graph[st].push_back(dest);
        graph[dest].push_back(st);
    }
    for(int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(V, vis1);
    cout<<'\n';
    queue<int>q;
    vis2[V] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout<<cur<<' ';
        for(auto e : graph[cur]){
            if(vis2[e]) continue;
            q.push(e);
            vis2[e] = 1;
        }
    }
}

// N = 3
// 0 0 0 -> 1번노드랑 1, 2, 3번 노드랑 연결되어있는지.
// 0 0 0 -> 2번노드랑 1, 2, 3번 노드랑 연결되어있는지.
// 0 0 0 -> 3번노드랑 1, 2, 3번 노드랑 연결되어있는지.

// 1 2
// 1 3

// 0 1 1
// 0 0 0
// 0 0 0
// 1번노드부터 탐색 -> cur == 1

// 알고리즘
// 교내 프로그래밍 대회(알고리즘 대회)
// 완전탐색 DP 그래프 
// 그래프 -> 구현