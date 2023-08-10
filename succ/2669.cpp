#include <iostream>
using namespace std;
int board[101][101], ans;
int main(){
    for(int i=0; i<4; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        for(int r=x1; r<x2; r++)
            for(int r2 = y1; r2<y2; r2++)
                board[r][r2] = 1;
    }
    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++)
            if(board[i][j]) ans += 1;
    cout<<ans;
}