//
// Created by 이재훈 on 25. 3. 27.
//
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string board[11];
int Rx, Ry, Bx, By, Hx, Hy, dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, visR[11][11], visB[11][11], ans = 987654321;

int main() {
    // Initiate
    int N, M; cin>>N>>M;
    for(int i=0;i<N;i++) cin>>board[i];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            if (board[i][j]=='R') {
                Rx = i; Ry = j;
            }
            if (board[i][j] == 'B') {
                Bx = i; By = j;
            }
            if (board[i][j] == 'O') {
                Hx = i; Hy = j;
            }
        }
    }

    // Solve
    queue< pair<pair<int,int>, pair<int,int > > >q;
    queue<int>q2;
    q.push(make_pair(make_pair(Rx, Ry), make_pair(Bx, By)));
    q2.push(0);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        auto Rp = cur.first, Bp = cur.second;
        int ccount = q2.front(); q2.pop();
        if (ccount >= 10) break;
        for (int dir=0; dir<4; dir++) {
            int nRx = Rp.first, nRy = Rp.second, nBx = Bp.first, nBy = Bp.second;
            int b = 0, a = 0;

            bool Rcheck=false, Bcheck=false;
            while (board[nRx][nRy] != '#') {
                int nx = nRx+dx[dir], ny = nRy+dy[dir];
                if (board[nx][ny] == '#'){
                    break;
                }
                if (nx == nBx && ny == nBy) {
                    b = 1;
                    break;
                }
                if (board[nx][ny] == 'O') {
                    Rcheck = true;
                    nRx = -1; nRy = -1;
                    break;
                }
                if (board[nx][ny] != '#') {
                    nRx = nRx + dx[dir]; nRy = nRy + dy[dir];
                }
            }
            while (board[nBx][nBy] != '#') {
                int nx = nBx+dx[dir], ny = nBy+dy[dir];
                if (board[nx][ny] == 'O') {
                    Bcheck = true;
                    break;
                }
                if (nx == nRx && ny == nRy) {
                    a = 1;
                    break;
                }
                if (board[nx][ny] == '#') {
                    break;
                }
                if (board[nx][ny] != '#') {
                    nBx = nBx + dx[dir]; nBy = nBy + dy[dir];
                }
            }
            if (b) {
                nRx = nBx - dx[dir]; nRy = nBy - dy[dir];
            }else if (a) {
                nBx = nRx - dx[dir]; nBy = nRy - dy[dir];
            }
            if (Bcheck) continue;
            if (Rcheck) {
                ans = min(ans, ccount + 1);
                continue;
            }
            q.push(make_pair(make_pair(nRx, nRy), make_pair(nBx, nBy)));
            q2.push(ccount + 1);
        }
    }
    if (ans == 987654321) cout<<-1;
    else cout<<ans;
}