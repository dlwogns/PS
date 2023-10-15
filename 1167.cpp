#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int V;
vector<vector<pair<int,int> > >graph(100001);
pair<int,int> func(int stnode){
    queue<pair<int,int > >q;
    int check_node = 0, cdist = 0;
    int vis[100001] = {0};
    vis[stnode] = 1;
    q.push(make_pair(stnode, 0));
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto e : graph[cur.first]){
            if(vis[e.first]) continue;
            vis[e.first] = 1;
            q.push(make_pair(e.first, e.second+cur.second));
            if(e.second + cur.second > cdist){
                check_node = e.first;
                cdist = cur.second + e.second;
            }
        }
    }
    return make_pair(check_node, cdist);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>V;
    for(int i=1; i<=V; i++){
        int node, dest, dist;
        cin>>node;
        while(cin>>dest && dest != -1){
            cin>>dist;
            graph[node].push_back(make_pair(dest, dist));
        }
    }
    cout<<func(func(1).first).second;
}