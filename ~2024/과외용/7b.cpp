#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int T, dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int main(){
    cin>>T;
    while(T--){
        int N, M; cin>>M>>N;
        char board[501][501];
        int vis[501][501] = {0}, ans=0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin>>board[i][j];
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++){
                if(vis[i][j] || board[i][j] == 'X') continue;
                queue<pair<int,int > > q;
                q.push(make_pair(i,j));
                vis[i][j] = 1;
                ans += 1;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0; dir<4; dir++){
                        int nx = dx[dir] + cur.first;
                        int ny = dy[dir] + cur.second;
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(vis[nx][ny] || board[nx][ny] == 'X') continue;
                        q.push(make_pair(nx,ny));
                        vis[nx][ny] = 1;
                    }
                }
            }
        cout<<ans<<'\n';
    }
}