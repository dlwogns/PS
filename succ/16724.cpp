#include <iostream>
#include <string>
using namespace std;
int N, M, vis[1001][1001], ans, k=1;
string board[1001];
void func(int x, int y){
    if(x >= N || x<0 || y>=M||y<0)
        return;
    if(vis[x][y] == k)
        return;
    else if(vis[x][y] && vis[x][y] != k){
        ans -= 1;
        return;
    }
    vis[x][y] = k;
    if(board[x][y] == 'U')
        func(x-1,y);
    else if(board[x][y]=='D')
        func(x+1,y);
    else if(board[x][y]=='L')
        func(x,y-1);
    else
        func(x, y+1);
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>board[i];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(vis[i][j]) continue;
            func(i,j);
            k++;
            ans += 1;
        }
    cout<<ans;

}