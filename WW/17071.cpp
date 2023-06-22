#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define INF 987654321
using namespace std;
int N, K, ans = INF, seconda[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>K;
    // initialize second array
    for(int i=1; i<=1001; i++)
        seconda[i] = seconda[i-1] + i;
    
    vector<int>dist(500001, INF);
    dist[N] = 0;
    queue<pair<int,int> >q;
    q.push(make_pair(N, 0));
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int arr[3] = {1,-1,2};
        for(int i=0; i<3; i++){
            
            if(arr[i] == 2){
                if(cur.first == 0) continue;
                if(cur.first * 2 > 500000) continue;
                if(dist[cur.first*2] > cur.second+1){
                    q.push(make_pair(cur.first*2, cur.second+1));
                    dist[cur.first*2] = cur.second + 1;
                }
                continue;
            }
            int cur_node = cur.first;
            int cur_dist = cur.second;
            int nxt_node = cur_node + arr[i];
            if(nxt_node < 0 || nxt_node > 500000) continue;
            if(dist[nxt_node] > cur_dist + 1){
                q.push(make_pair(nxt_node, cur_dist + 1));
            }
        }
    }
}