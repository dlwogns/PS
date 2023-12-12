#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int board[101][101], dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, N;
int island[101][101];
vector<pair<int,int > > v;
int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>board[i][j];
    int isnum = 1;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(board[i][j] == 0 || island[i][j]) continue;
            queue<pair<int,int > > q;
            q.push(make_pair(i, j));
            island[i][j] = isnum;
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<0||nx>=N||ny<0||ny>=N) continue;
                    if(island[nx][ny] || board[nx][ny] == 0) continue;
                    island[nx][ny] = isnum;
                    q.push(make_pair(nx, ny));
                }
            }
            isnum+=1;
        }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(board[i][j] == 0) continue;
            for(int dir = 0; dir<4; dir++){
                int nx = i + dx[dir];   
                int ny = j + dy[dir];
                if(nx<0||nx>=N||ny<0||ny>=N) continue;
                if(board[nx][ny] == 0){
                    v.push_back(make_pair(i, j));
                    continue;
                }
            }
        }
    int ans = 987654321;
    for(auto e : v){
        int cur_num = island[e.first][e.second];
        int vis[101][101] = {0};
        queue<pair<int, int > > q;
        q.push(make_pair(e.first, e.second));
        vis[e.first][e.second] = 1;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir<4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0||nx>=N||ny<0||ny>=N) continue;
                if(vis[nx][ny] || island[nx][ny] == cur_num) continue;
                if(island[nx][ny] != cur_num && island[nx][ny]){
                    ans = min(ans, vis[cur.first][cur.second]-1);
                    break;
                }
                q.push(make_pair(nx, ny));
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
        }
    }
    cout<<ans;
}
