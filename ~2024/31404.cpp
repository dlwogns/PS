#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int H, W, R, C, D, ans, dustCheck, board[65][65], vis[65][65], chkvis[65][65], dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
string A[65], B[65];
bool checkCycle(int x, int y, int d){
    queue<pair< int ,int > >q;
    int cvis[65][65] = {0}, dcvis[65][65]={0};
    q.push(make_pair(x, y));
    cvis[x][y] = 1;
    while(!q.empty()){
        pair<int,int>cur = q.front(); q.pop();
        int nx = cur.first+dx[d];
        int ny = cur.second + dy[d];
        if(nx >= H || nx < 0 || ny >= W || ny < 0) return true;
        if(board[nx][ny]) return false;
        d = (d + B[nx][ny] - '0')%4;
        if(cvis[nx][ny]&&dcvis[nx][ny] == d+1) return true;
        q.push(make_pair(nx, ny));
        cvis[nx][ny] = 1;
        dcvis[nx][ny] = d+1;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<65; i++)
        for(int j=0; j<65; j++){
            board[i][j] = 1;
            vis[i][j] = -1;
        }
    cin>>H>>W>>R>>C>>D;
    for(int i=0; i<H; i++)
        cin>>A[i];
    for(int i=0; i<H; i++)
        cin>>B[i];
    // D: 0 -> 위 1 -> 오 2 -> 아 3 -> 왼
    queue< pair<int,int > > q;
    q.push(make_pair(R, C));
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        //cout<<cur.first<<' '<<cur.second<<endl;
        // 범위 벗어남
        if(cur.first >= H || cur.second >= W || cur.first < 0 || cur.second < 0) {
            break;
        }
        if(board[cur.first][cur.second]) {
            // 먼지 있을떄
            board[cur.first][cur.second] = 0;
            dustCheck += 1;
            if(dustCheck == H*W) break; 
            D = (D + (A[cur.first][cur.second] - '0'))%4;
        }
        else if(board[cur.first][cur.second] == 0){
            // 먼지 없을때
            D = (D + (B[cur.first][cur.second] - '0'))%4;
            if(checkCycle(cur.first, cur.second, D)) break;
        }
        q.push(make_pair(cur.first + dx[D], cur.second + dy[D]));
        vis[cur.first][cur.second] = D;
        ans += 1;
    }
    cout<<ans;
}