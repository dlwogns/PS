#include <iostream>
#include <cmath>
using namespace std;
int board[21][21],likeArr[401][401],  N, dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, ans;

int main() {
    cin>>N;
    for(int i=1; i<=N*N; i++) {
        int snum, mr, mc, likeNum=-1, emptyNum=-1;
        cin>>snum;
        for(int j=0; j<4; j++) {
            int likeInput; cin>>likeInput;
            likeArr[snum][likeInput] = 1;
        }
        for(int r=0; r<N; r++)
            for(int c=0; c<N; c++) {
                if(board[r][c]) continue;
                int curr = r, curc = c, like = 0, emp = 0;
                for(int dir = 0; dir<4; dir++) {
                    int nx = curr + dx[dir];
                    int ny = curc + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(board[nx][ny] == 0) emp += 1;
                    else {
                        if(likeArr[snum][board[nx][ny]]) 
                            like += 1;
                    }
                }
                if(like > likeNum) {
                    mr = curr; mc = curc; emptyNum = emp; likeNum = like;
                }else if(like == likeNum && emp > emptyNum) {
                    mr = curr; mc = curc; likeNum = like; emptyNum = emp;
                }else if(like==likeNum && emp == emptyNum){
                    if(curr < mr) {
                        mr = curr; mc = curc;
                    }
                    else if( curr == mr && curc < mc) {
                        mr = curr; mc = curc; 
                    }
                }

            }
        board[mr][mc] = snum;
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            int check = 0;
            for(int dir = 0; dir<4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if(likeArr[board[i][j]][board[nx][ny]]) check += 1;
            }
            ans += pow(10, check-1);
        }
    cout<<ans;
}