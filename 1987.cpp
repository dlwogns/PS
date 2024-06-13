#include <iostream>
#include <string>
using namespace std;

int R, C, dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, ans=0;
string board[21];

void func(int i, int j, int a, int* alpha) {
    for(int dir=0; dir<4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx<0||nx>=R||ny<0||ny>=C) continue;
        if(alpha[board[nx][ny]-'A']) continue;
        alpha[board[nx][ny]-'A'] = 1;
        func(nx, ny, a+1, alpha);
        alpha[board[nx][ny]-'A'] = 0;
    }
    ans = max(ans, a);
}

int main() {
    cin>>R>>C;
    for(int i=0; i<R; i++)
        cin>>board[i];
    int alpha[26] = {0};
    alpha[board[0][0] - 'A'] = 1;
    func(0,0,1,alpha);
    cout<<ans;
}