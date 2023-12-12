#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define piii pair<int, pair<int,int > >
#define INTMAX 987654321
using namespace std;
int N, M;
string board[1001];
int dist[1001][1001][2], dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>board[i];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            dist[i][j][0] = INTMAX;
            dist[i][j][1] = INTMAX;
        }
    dist[0][0][0] = 1;
    queue< piii >q;
    q.push(make_pair(0, make_pair(0,0)));
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.second.first + dx[i];
            int ny = cur.second.second + dy[i];
            if(nx<0|| nx>=N||ny<0||ny>=M) continue;
            if(cur.first == 1 && board[nx][ny] == '1') continue;
            if(board[nx][ny] == '1'){
                if(dist[nx][ny][1] != INTMAX) continue;
                dist[nx][ny][1] = dist[cur.second.first][cur.second.second][cur.first]+1;
                q.push(make_pair(1, make_pair(nx,ny)));
            }else{
                if(dist[nx][ny][cur.first] != INTMAX) continue;
                dist[nx][ny][cur.first] = dist[cur.second.first][cur.second.second][cur.first]+1;
                q.push(make_pair(cur.first, make_pair(nx,ny)));
            }
        }
    }
    int ans = min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
    if(ans == INTMAX)
        cout<<-1;
    else
        cout<<ans;


}