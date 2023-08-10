#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
string board[101];
int W, H, dist[101][101], dx[5]={100,1,0,-1,0}, dy[5]={100,0,1,0,-1};
vector<pair<int,int>>cp;
int main(){
    cin>>W>>H;
    for(int i=0; i<H; i++)
        cin>>board[i];
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++){
            if(board[i][j]=='C')
                cp.push_back({i, j});
        }
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            dist[i][j] = INF;

    dist[cp[0].first][cp[0].second] = 0;
    queue<pair<pair<int,int>,pair<int,int>>>q;
    q.push({{cp[0].first, cp[0].second},{0, 0}});
    while(!q.empty()){
        auto cur = q.front();
        if(dist[cur.first.first][cur.first.second] != cur.second.first) {
            q.pop();
            continue;
        }
        q.pop();
        for(int dir = 1; dir<=4; dir++){
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];
            if(nx>=H || nx < 0 || ny >= W || ny < 0) continue;
            if(nx == cp[0].first && ny == cp[0].second) continue;
            if(board[nx][ny] =='*') continue;
            if(cur.second.second == 0){
                dist[nx][ny] = 0;
                q.push({{nx,ny}, {0,dir}});
                continue;
            }
            if(cur.second.second%2 != dir%2){
                if(dist[nx][ny] >= dist[cur.first.first][cur.first.second]+1){
                    dist[nx][ny] = dist[cur.first.first][cur.first.second]+1;
                    q.push({{nx, ny}, {dist[nx][ny], dir}});
                }
            }else if(cur.second.second == dir){
                if(dist[nx][ny] >= dist[cur.first.first][cur.first.second]){
                    dist[nx][ny] = dist[cur.first.first][cur.first.second];
                    q.push({{nx, ny}, {dist[nx][ny],dir}});
                }
            }
        }
    }
    cout<<dist[cp[1].first][cp[1].second];
}