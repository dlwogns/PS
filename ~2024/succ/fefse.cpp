#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#define INF 987654321
using namespace std;
int N, M, vis[101][101], dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
string board[101];
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>board[i];
        
    queue<pair<int,int > >q;
    q.push(make_pair(0,0));
    vis[0][0] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(board[nx][ny] == '0') continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    
    cout<<vis[N-1][M-1];
}