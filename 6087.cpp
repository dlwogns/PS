#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#define INTMAX 987654321
using namespace std;
int W, H, dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, ans[101][101], dirList[101][101][4];
// 하 -> 0, 우 -> 1, 상 -> 2, 좌 -> 3
vector<pair<int,int > > C;
string board[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>W>>H;
    for(int i=0; i<H; i++)
        cin>>board[i];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(board[i][j] == 'C'){
                C.push_back(make_pair(i,j));
            }
            ans[i][j] = INTMAX;
        }
    }
    ans[C[0].first][C[0].second] = 0;
    queue<pair<pair<int,int >,pair<int,int> > >q;
    for(int i=0; i<4; i++) {
        int nx = C[0].first+dx[i];
        int ny = C[0].second+dy[i];
        if(nx<0 || nx >= H || ny < 0 || ny >= W) continue;
        if(board[nx][ny] == '*') continue;
        ans[nx][ny] = 0;
        dirList[nx][ny][i] = 1;
        q.push(make_pair(make_pair(nx, ny), make_pair(i, 0)));
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            int tmp = cur.second.second;
            if(nx<0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] == '*') continue;
            if(i == cur.second.first && (i+2)%4 == cur.second.first) continue;
            if(i != cur.second.first) tmp += 1;
            if(ans[nx][ny] == tmp && dirList[nx][ny][i] == 1) continue;
            if(ans[nx][ny] >= tmp) {
                dirList[nx][ny][i] = 1;
                ans[nx][ny] = tmp;
                q.push(make_pair(make_pair(nx, ny), make_pair(i, tmp)));
            }
        }
    }
    cout<<ans[C[1].first][C[1].second];
}