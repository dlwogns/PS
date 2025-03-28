#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int M, N, board[1001][1001], dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, ans;
queue<pii>q;
int main(){
    fastio;
    cin>>M>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 1) q.push(make_pair(i, j));
        }
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny > M) continue;
            if(board[nx][ny] != 0) continue;
            board[nx][ny] = board[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(board[i][j] == 0){
                cout<<-1;
                return 0;
            }else
                ans = max(ans, board[i][j]);
    cout<<ans-1;

    
}