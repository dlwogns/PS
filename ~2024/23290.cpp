// 격자는 4 * 4. 맨 위칸은 (1, 1)
// 1. 복제마법 시전. 원래 있던 물고기가 그대로 모든 작업을 다 한 후에 복제됨.
// 2. 모든 물고기가 정해진 방향으로 이동.
//    상ㅓ가 있는 칸, 물고기 냄새가 있는 칸, 격자를 벗어난 칸에는 이동 X.
//    이동할 수 있는 칸이 없으면 이동 X.
//    45도 반시계 방향으로 방향을 이동하면서 이동 가능한 곳을 찾음.
// 3. 사전순 64가지 방법 중에 물고기의 수가 가장 많은 방법으로 상어가 이동.
//    이때 사라지는 물고기는 물고기 냄새를 남긴다.
// 4. 두번 연습전 물고기 냄새가 전부 사라진다.
// 5. 물고기가 복제된다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int M, S, cur_r, cur_c;
int dx[8]={0,-1,-1,-1,0,1,1,1}, dy[8]={-1,-1,0,1,1,1,0,-1};
int sdx[4]={-1, 0, 1, 0}, sdy[4]={0, -1, 0, 1};
vector<pair<int,long long> > fish[5][5];
vector<pair<int, long long> > fish_aftermove[5][5];
deque<int > smell[5][5];


// check fish_smell
int check_fishcnt;
vector<int> shark_move_v;



void shark_move(int cnt, vector<int>& v) {
    if(cnt == 3) {
        int cur_x = cur_r, cur_y = cur_c;
        int check_fishcnt_per_move = 0;
        int vis[5][5] = {0};
        for(auto dir : v) {
            cur_x = cur_x + sdx[dir];
            cur_y = cur_y + sdy[dir];
            if(cur_x<1||cur_x>4||cur_y<1||cur_y>4) return;
            if(fish_aftermove[cur_x][cur_y].empty() || vis[cur_x][cur_y]) continue;
            vis[cur_x][cur_y] = 1;
            for(auto fi : fish_aftermove[cur_x][cur_y]){
                check_fishcnt_per_move += fi.second;
            }
        }
        
        if(check_fishcnt < check_fishcnt_per_move) {
            check_fishcnt = check_fishcnt_per_move;
            shark_move_v.clear();
            for(auto d : v) shark_move_v.push_back(d);
        }
        return;
    }
    for(int i=0; i<=3; i++) {
        v.push_back(i);
        shark_move(cnt+1, v);
        v.pop_back();
    }
}
int main() {
    cin>>M>>S;
    for(int i=0; i<M; i++) {
        int r, c, d; cin>>r>>c>>d;
        fish[r][c].push_back(make_pair(d-1, 1));
    }
    cin>>cur_r>>cur_c;
    for(int s=1; s<=S; s++) {
        // c2 start
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++) {
                for(auto e : fish[i][j]) {
                    int dir = e.first, fcnt = e.second;
                    for(int d=0; d<8; d++) {
                        int dirpd = (dir-d)%8;
                        if(dirpd < 0) dirpd += 8;
                        int nx = dx[dirpd] + i;
                        int ny = dy[dirpd] + j;
                        if(nx < 1 || nx > 4 || ny < 1 || ny > 4) continue;
                        if(!smell[nx][ny].empty()) continue;
                        if(nx == cur_r && ny == cur_c) continue;
                        fish_aftermove[nx][ny].push_back(make_pair(dirpd, fcnt));
                        break;
                    }
                }
            }
        // c2 end
        // c3 start
        vector<int> v;
        shark_move(0, v);
        for(int dir : shark_move_v) {
            cur_r = cur_r + sdx[dir];
            cur_c = cur_c + sdy[dir];
            if(!fish_aftermove[cur_r][cur_c].empty()){
                smell[cur_r][cur_c].push_back(s);
                while(!fish_aftermove[cur_r][cur_c].empty())
                    fish_aftermove[cur_r][cur_c].pop_back();
            }
        }
        shark_move_v.clear();
        check_fishcnt = 0;
        // c3 end
        // c4 start
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++) {
                if(smell[i][j].empty()) continue;
                while(!smell[i][j].empty()) {
                    if(smell[i][j].front() < s-1)
                        smell[i][j].pop_front();
                    else break;
                }
            }
        // c4 end
        // c5 start
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++) {
                if(fish_aftermove[i][j].empty()) continue;
                if(fish[i][j].empty()) {
                    for(auto e : fish_aftermove[i][j]) {
                        fish[i][j].push_back(e);
                    }
                }else {
                    for(auto e : fish_aftermove[i][j]) {
                        int chk = 0;
                        for(auto iter = fish[i][j].begin(); iter != fish[i][j].end(); iter++){
                            if(e.first == (*iter).first) {
                                (*iter).second += e.second;
                                chk = 1;
                                break;
                            }
                        }
                        if(chk) continue;
                        fish[i][j].push_back(e);
                    }
                }
                fish_aftermove[i][j].clear();
            }

        //←, ↖, ↑, ↗, →, ↘, ↓, ↙ 
        // c5 end
    }
    long long ans = 0;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            for(auto e : fish[i][j]) {
                ans += e.second;
            }
        }
    }
    cout<<ans;

}