#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define INF 2000000001
using namespace std;
int T, node_num, edge_num, dest_num, s, g, h;
pair<vector<double>, vector<int>> ekdlr(int st, vector<vector<pair<int,double>>>&gr){
    vector<double>dist(node_num+1, INF);
    vector<int>an(node_num+1, 0);
    dist[st] = 0;
    priority_queue<pair<double,int>>pq;
    pq.push({0,st});
    while(!pq.empty()){
        int cur_node = pq.top().second;
        double cur_dist = pq.top().first;
        pq.pop();
        for(int i=0; i<gr[cur_node].size(); i++){
            int nxt_node = gr[cur_node][i].first;
            double nxt_dist = cur_dist + gr[cur_node][i].second;
            if(dist[nxt_node] > nxt_dist){
                dist[nxt_node] = nxt_dist;
                pq.push({nxt_dist, nxt_node});
            }
        }
    }
    return {dist, an};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>node_num>>edge_num>>dest_num>>s>>g>>h;
        vector<vector<pair<int,double>>>graph(node_num+1);
        vector<int>dest;
        for(int i=0; i<edge_num; i++){
            int a, b;
            double d;
            cin>>a>>b;
            cin>>d;
            if((a==g && b == h) || (a==h && b==g)){
                graph[a].push_back({b,d-0.1});
                graph[b].push_back({a,d-0.1});
            }
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
            if(floor(check.first[d]) != check.first[d]) ans.push_back(d);
        }
        // cout<<endl;
        // for(auto e : check.first){
        //     cout<<e<<' ';
        // }
        // cout<<endl;
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<' ';
        cout<<'\n';        
    }
}