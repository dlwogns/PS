#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define INF 987654321
using namespace std;
int N, M, H, ans = INF;
int board[32][32];
int check(){
    for(int i=1; i<=N; i++){
        int x = i, y=1;
        while(y != H){
            if(board[y][x]) x++;
            else if(board[y][x-1]) x--;
            y+=1;
        }
        if(x != i) return 0;
    }
    return 1;

}
void bt(int limit, int count){
    if(count == limit){
        if(check())
            ans = min(ans, count);
        return;
    }
    for(int i=1; i<=H; i++)
        for(int j=1; j<N; j++){
            if(board[i][j] || board[i][j+1] || board[i][j-1]) continue;
            board[i][j] = 1;
            bt(limit, count+1);
            board[i][j] = 0;
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>M>>H;
    // N -> 세로선 M -> 가로선 H -> 높이
    for(int i=1; i<=M; i++){
        int hei, po;
        cin>>hei>>po;
        board[hei][po] = 1;
    }
    for(int i=0; i<=3; i++)
        bt(i,0);

    if(ans == INF) cout<<-1;
    else cout<<ans;

}