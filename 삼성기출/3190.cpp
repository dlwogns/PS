#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 1행 1열이 기준!!!!!!
// L은 왼쪽으로 회전, D는 오른쪽으로 회전
// 오 아 왼 위
int N, K, L, board[101][101], dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, dirb[101][101], vis[101][101];
char dir_change[10001];

int main(){
    cin>>N>>K;
    for (int i=0; i<K; i++) {
        int x, y; cin>>x>>y;
        board[x][y] = 1;
        // apple
    }
    cin>>L;
    for (int i=0; i<L; i++) {
        int X; char C;
        cin>>X; cin>>C;
        dir_change[X] = C;
    }
    // 뱀은 처음에 오른쪽을 향한다.

    queue<pair<int,int> >q;
    q.push(make_pair(1, 1));
    vis[1][1] = 1;
    int sec = 0, dir = 0, tx=1, ty = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        sec += 1;
        // 머리를 다음칸에 위치시킴
        dirb[cur.first][cur.second] = dir;
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];


        // 벽이나 자기 자신한테 닿았을 경우
        if (nx > N || nx <= 0 || ny > N || ny <= 0 || vis[nx][ny]) break;

        // 이동한 칸에 사과 체크
        if (!board[nx][ny]){
            // 없을 경우 꼬리를 이동.
            vis[tx][ty] = 0;
            int dir_s = dirb[tx][ty];
            tx += dx[dir_s];
            ty += dy[dir_s];
        }else {
            // 있을경우
            board[nx][ny] = 0;
        }

        if (dir_change[sec] == 'D') dir = (dir+1)%4;
        if (dir_change[sec] == 'L') {
            dir -= 1;
            if (dir == -1) dir += 4;
        }

        vis[nx][ny] = 1;
        q.push(make_pair(nx, ny));
    }
    cout<<sec;

}