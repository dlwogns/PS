#include <iostream>
#include <string>
using namespace std;
int R, C, dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
string board[501];
int main(){
    cin>>R>>C;
    for(int i=0; i<R; i++)
        cin>>board[i];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
            if(board[i][j] != 'S') continue;
            for(int dir = 0; dir<4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(board[nx][ny] == 'S') continue;
                if(board[nx][ny] == 'W'){
                    cout<<0;
                    return 0;
                }
                board[nx][ny] = 'D';
            }
        }
    cout<<1<<'\n';
    for(int i=0; i<R; i++)
        cout<<board[i]<<'\n';
}
