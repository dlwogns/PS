#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, ans[51][51][4], ansNum = 987654322, startX, startY;
string board[51];
void solve(int x, int y) {
    queue<pair< pair<int, int>, pair<int, int> > >q;
    q.push(make_pair(make_pair(x, y), make_pair(-1, 0)));
    while(!q.empty()) {
        auto cur = q.front().first; int curDir = q.front().second.first; int curDist = q.front().second.second; q.pop();
        char curBoard = board[cur.first][cur.second];
        if(curBoard == '#') {
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0||nx>=N||ny<0||ny>=N||board[nx][ny] == '*') continue;
                if(ans[nx][ny][dir] > curDist) {
                    ans[nx][ny][dir] = curDist;
                    q.push(make_pair(make_pair(nx,ny), make_pair(dir, curDist)));
                }
                if(board[nx][ny] == '#'&& (nx != startX || ny != startY)) ansNum = min(ansNum, ans[nx][ny][dir]);
            }
        }else if(curBoard == '!') {
            for(int dir=0; dir<4; dir++) {
                if(dir == (curDir+2)%4) continue;
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0||nx>=N||ny<0||ny>=N||board[nx][ny] == '*') continue;
                int addiDist = (curDir == dir)?0:1;
                if(ans[nx][ny][dir] > curDist + addiDist) {
                    ans[nx][ny][dir] = curDist + addiDist;
                    q.push(make_pair(make_pair(nx,ny), make_pair(dir, curDist + addiDist)));
                }
                if(board[nx][ny] == '#' && (nx != startX || ny != startY)) ansNum = min(ansNum, ans[nx][ny][dir]);
            }
        }else if(curBoard == '.') {
            int nx = cur.first + dx[curDir];
            int ny = cur.second + dy[curDir];
            if(nx<0||nx>=N||ny<0||ny>=N||board[nx][ny] == '*') continue;
            if(ans[nx][ny][curDir] > curDist) {
                ans[nx][ny][curDir] = curDist;
                q.push(make_pair(make_pair(nx,ny), make_pair(curDir, curDist)));
            }
            if(board[nx][ny] == '#'&& (nx != startX || ny != startY)) ansNum = min(ansNum, ans[nx][ny][curDir]);
        }
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++) cin>>board[i];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(board[i][j] == '#'){
                startX = i; startY = j;
            }
            for(int k=0; k<4; k++)
                ans[i][j][k] = 987654321;
        }
    for(int i=0; i<4; i++)
        ans[startX][startY][i] = 0;
    solve(startX, startY);
    cout<<ansNum;
    

}