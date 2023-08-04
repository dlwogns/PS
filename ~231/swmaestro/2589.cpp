#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#define INF 987654321
using namespace std;
int N, M, ans, dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
vector<string>board;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        board.push_back(s);
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(board[i][j] == 'W') continue;
            int dist[51][51];
            for(int k=0; k<N; k++)
                for(int l=0; l<M; l++)
                    dist[k][l] = INF;

            queue<pair<int,int> >q;
            q.push(make_pair(i, j));
            dist[i][j] = 0;
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(board[nx][ny] == 'W') continue;
                    if(dist[nx][ny] <= dist[cur.first][cur.second]+1) continue;
                    dist[nx][ny] = dist[cur.first][cur.second]+1;
                    q.push(make_pair(nx, ny));
                }
            }
            for(int k=0; k<N; k++)
                for(int l=0; l<M; l++){
                    if(dist[k][l] == INF) continue;
                    ans = max(ans, dist[k][l]);
                }
        }
    cout<<ans;

}