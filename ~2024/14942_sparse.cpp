#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
int N, ant[100001];
vector<vector<pair<int,int > > > v(100001);
pair<ll,ll> table[18][100001];

void bfs(){
    queue<int>q;
    bool check[100001] = {0};
    q.push(1);
    check[1] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto e : v[cur]){
            if(check[e.first]) continue;
            table[0][e.first] = make_pair(cur, e.second);
            check[e.first] = 1;
            q.push(e.first);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>ant[i];
    for(int i=0; i<N-1; i++){
        int a, b, c; cin>>a>>b>>c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    // 희소배열 초기화.
    bfs();
    for(int i=1; i<=17; i++)
        for(int j=1; j<=N; j++){
            table[i][j].first = table[i-1][table[i-1][j].first].first;
            table[i][j].second = table[i-1][table[i-1][j].first].second + table[i-1][j].second;
        }
        
    for(int i=1; i<=N; i++){
        int target_node = i;
        for(int j=17; j>=0; j--){
            if(table[j][target_node].first != 0 && table[j][target_node].second <= ant[i]){
                ant[i] -= table[j][target_node].second;
                target_node = table[j][target_node].first;
            }
        }
        cout<<target_node<<'\n';
    }

}