#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int graph[10][10], vis[10][10], dx[4] = {1,0,-1,0} , dy[4] = {0,1,0,-1};
// BFS (breath first search)
// 점은 node, 선은 edge
// 2차원 배열 arr[3][3]
// (0,0) (0,1) (0,2)
// (1,0) (1,1) (1,2)
// (2,0) (2,1) (2,2)
// (0,0) -> (1,0) -> (0,1) -> (1,1) -> (2,0)
// queue
// queue((1,1)(2,0)(0,2))
int main(){
    queue<pair<int, int > >q;
    q.push(make_pair(0,0));
    vis[0][0] = 1;
    while(!q.empty()){
        auto cur_node = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur_node.first + dx[dir];
            int ny = cur_node.second + dy[dir];
            if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
            if(vis[nx][ny]) continue;
            q.push(make_pair(nx, ny));
            vis[nx][ny] = 1;
        }
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            cout<<vis[i][j]<<' ';
        cout<<endl;
    }
}