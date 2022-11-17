#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
string board[101];
int W, H, dist[101][101],dirc[101][101], dx[5]={100,1,0,-1,0}, dy[5]={100,0,1,0,-1};
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
    //dijstra
    //상 1 우 2 하 3 좌 4
    dist[cp[0].first][cp[0].second] = 0;
    queue<pair<int,int>>q;
    q.push({cp[0].first, cp[0].second});
    while(!q.empty()){
        pair<int,int>cur = q.front();
        q.pop();
        for(int dir=1; dir<=4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx >= H || nx < 0 || ny >= W || ny < 0) continue;
            if(nx == cp[0].first && ny == cp[0].second) continue;
            if(board[nx][ny] == '*') continue;
            if(dirc[cur.first][cur.second] == 0){
                dirc[nx][ny] = dir;
                dist[nx][ny] = 0;
                q.push({nx, ny});
                continue;
            }
            if(dirc[cur.first][cur.second]%2 != dir%2){
                if(dist[nx][ny] > dist[cur.first][cur.second]+1){
                    dist[nx][ny] = dist[cur.first][cur.second]+1;
                    dirc[nx][ny] = dir;
                    q.push({nx, ny});
                }
            }else if(dirc[cur.first][cur.second] == dir){
                if(dist[nx][ny] > dist[cur.first][cur.second]){
                    dist[nx][ny] = dist[cur.first][cur.second];
                    dirc[nx][ny] = dir;
                    q.push({nx, ny});
                }
            }
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++)
            cout<<dist[i][j]<<' ';
        cout<<endl;
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++)
            cout<<dirc[i][j]<<' ';
        cout<<endl;
    }
    cout<<dist[cp[1].first][cp[1].second];
}