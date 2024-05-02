#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#define INTMAX 987654321
using namespace std;
int R, C, check;
string board[1501];
int ans = 0, dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, vis[1501][1501];
queue<pair<int,int > > q, q2, sq, sq2;
int main() {
    cin>>R>>C;
    for(int i=0; i<R; i++){
        cin>>board[i];
    }
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            if(board[i][j] == '.' || board[i][j] == 'L'){
                q2.push(make_pair(i, j));
            }
            if(board[i][j] == 'L'){
                if(sq2.empty()){
                    sq2.push(make_pair(i, j));
                    vis[i][j] = 1;
                }
            }
        }
        while(!check) {
            while(!q2.empty()){
                q.push(q2.front()); q2.pop();
            }
            while(!sq2.empty()){
                sq.push(sq2.front()); sq2.pop();
            }
            while(!sq.empty() && !check) {
                auto cur = sq.front(); sq.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx<0||nx>=R||ny<0||ny>=C) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny]=='.'){
                        sq.push(make_pair(nx, ny));
                        vis[nx][ny] = 1;
                    }
                    if(board[nx][ny] == 'X'){
                        sq2.push(make_pair(nx, ny));
                        vis[nx][ny] = 1;
                    }
                    if(board[nx][ny] == 'L') {
                        check = 1;
                        break;
                    }
                }
            }
            if(check){
                cout<<ans;
                break;
            }
            while(!q.empty() && !check) {
                auto cur = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx<0||nx>=R||ny<0||ny>=C) continue;
                    if(board[nx][ny] == 'X'){
                        q2.push(make_pair(nx, ny));
                        board[nx][ny] = '.';
                    }
                }
            }
            ans+=1;
        }
}