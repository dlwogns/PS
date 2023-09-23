// // 2차원 배열
// int arr[3][3];
// // bfs, dfs
// //bfs -> 넓이 우선 탐색
// //dfs -> 깊이 우선 탐색

// (0,0) (0,1) (0,2)
// (1,0) (1,1) (1,2)
// (2,0) (2,1) (2,2)

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int graph[10][10], visited[10][10], dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};

int main(){
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            //cin>>graph[i][j];


    queue<pair<int,int > >q;
    q.push(make_pair(0,0));
    visited[0][0] = 1;

    while(!q.empty()){
        pair<int,int> current_node = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = current_node.first + dx[dir];
            int ny = current_node.second + dy[dir];
            if(nx<0 || nx >= 10|| ny<0||ny>=10) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = visited[current_node.first][current_node.second] + 1;
            q.push(make_pair(nx,ny));
        }
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            cout<<visited[i][j]<<' ';
            
        cout<<endl;
    }
    
}
