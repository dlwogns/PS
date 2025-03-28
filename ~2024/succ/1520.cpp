#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,board[501][501], dp[501][501],vis[501][501],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x, int y){
    for(int dir=0; dir<4; dir++){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(nx < 0 || nx > N|| ny <0||ny>M) continue;
        //if(vis[nx][ny] ) continue;
        if(vis[nx][ny] ){
            if(board[nx][ny] > board[x][y]){
                dp[x][y] += dp[nx][ny];
            }
            continue;
        }
        if(board[nx][ny] <= board[x][y]) continue;
        vis[nx][ny] = 1;
        dfs(nx, ny);
        dp[x][y] += dp[nx][ny];
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>board[i][j];
    
    dp[0][0] =1;
    dfs(N-1,M-1);
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++)
    //         cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    cout<<dp[N-1][M-1];
    


}