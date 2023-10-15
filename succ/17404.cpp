#include <iostream>
#include <algorithm>
using namespace std;
int N, board[1001][3], dp1[1001][3], dp2[1001][3], dp3[1001][3];
int main(){
    cin>>N;
    for(int i=1; i<=N; i++)
        for(int j=0; j<3; j++)
            cin>>board[i][j];
    dp1[1][0] = 1000001;
    dp1[1][1] = board[1][1];
    dp1[1][2] = board[1][2];
    dp2[1][1] = 1000001;
    dp2[1][0] = board[1][0];
    dp2[1][2] = board[1][2];
    dp3[1][2] = 1000001;
    dp3[1][1] = board[1][1];
    dp3[1][0] = board[1][0];
    for(int i=2; i<=N; i++){
        for(int j=0; j<3; j++){
            dp1[i][j] = min(dp1[i-1][(j+1)%3],dp1[i-1][(j+2)%3]) + board[i][j];
        }
    }
    for(int i=2; i<=N; i++){
        for(int j=0; j<3; j++){
            dp2[i][j] = min(dp2[i-1][(j+1)%3],dp2[i-1][(j+2)%3]) + board[i][j];
        }
    }
    for(int i=2; i<=N; i++){
        for(int j=0; j<3; j++){
            dp3[i][j] = min(dp3[i-1][(j+1)%3],dp3[i-1][(j+2)%3]) + board[i][j];
        }
    }
    cout<<min(dp1[N][0],min(dp2[N][1],dp3[N][2]));
}