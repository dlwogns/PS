#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INTMAX 987654321;
using namespace std;
vector<vector<pair<int,int > > >v(100001);
int n, ant[100001], dist[100001];
void mindist(){
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto node : v[cur]){
            if(dist[node.first] > dist[cur] + node.second){
                dist[node.first] = dist[cur] + node.second;
                q.push(node.first);
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>ant[i];
    for(int i=0; i<n-1; i++){
        int a, b, c; cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(int i=2; i<=n; i++)
        dist[i] = INTMAX;
    mindist();
    for(int i=1; i<=n; i++){
        int curnode = i;
        int distsum = ant[i];
        while(1){
            if(curnode == 1){
                cout<<curnode<<'\n';
                break;
            }
            int checknode;
            for(auto node : v[curnode]){
                if(dist[node.first] > dist[curnode])
                    continue;
                checknode = node.first;
                distsum -= dist[curnode] - dist[node.first];
                break;
            }
            if(distsum < 0)
                break;
            curnode = checknode;
        }
        if(curnode != 1)
            cout<<curnode<<'\n';
    }
}
