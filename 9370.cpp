#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2000000001
using namespace std;
int T, node_num, edge_num, dest_num, s, g, h;
pair<vector<int>, vector<int>> ekdlr(int st, vector<vector<pair<int,int>>>&gr){
    vector<int>dist(node_num+1, INF);
    vector<int>be(node_num+1, INF);
    dist[st] = 0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,st});
    be[st] = st;
    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();
        for(int i=0; i<gr[cur_node].size(); i++){
            int nxt_node = gr[cur_node][i].first;
            int nxt_dist = cur_dist + gr[cur_node][i].second;
            if(dist[nxt_node] == nxt_dist){
                if(be[nxt_node] == g || be[nxt_node] == h) continue;
                if(cur_node == g || cur_node == h){
                    be[nxt_node] = cur_node;
                }
            }
            else if(dist[nxt_node] > nxt_dist){
                dist[nxt_node] = nxt_dist;
                pq.push({nxt_dist, nxt_node});
                be[nxt_node] = cur_node;
            }
        }
    }
    return {dist, be};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>node_num>>edge_num>>dest_num>>s>>g>>h;
        vector<vector<pair<int,int>>>graph(node_num+1);
        vector<int>dest;
        for(int i=0; i<edge_num; i++){
            int a, b, d;
            cin>>a>>b>>d;
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
        }
        for(int i=0; i<dest_num; i++){
            int d;
            cin>>d;
            dest.push_back(d);
        }
        auto check = ekdlr(s, graph);
        vector<int>ans;
        for(auto d : dest){
            if(check.first[d] == INF) continue;
            int c = d;
            while(check.second[c] != c){
                if((check.second[c] == h && c == g) || (check.second[c]==g && c == h)){
                    ans.push_back(d);
                    break;
                }
                c = check.second[c];
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<' ';
        cout<<'\n';        
    }
}