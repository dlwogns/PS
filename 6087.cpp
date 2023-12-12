#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int W, H, vis[101][101], dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, ans[101][101];
vector<pair<int,int > > C;
string board[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>W>>H;
    for(int i=0; i<H; i++)
        cin>>board[i];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++)
            if(board[i][j] == 'C'){
                C.push_back(make_pair(i,j));
            }
    }
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            ans[i][j] = 987654331;
    
    queue<pair<pair<int,int>,int > > q;
    q.push(make_pair(C[0],-1));
    ans[q.front().first.first][q.front().first.second] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        auto curnode = cur.first;
        int curdir = cur.second; 
        for(int dir=0; dir<4; dir++){
            int nx = curnode.first + dx[dir];
            int ny = curnode.second + dy[dir];
            if(nx<0 || nx>=H||ny<0||ny>=W||board[nx][ny] == '*') continue;
            if(vis[nx][ny]) continue;
            int nxt;
            (curdir == -1 || curdir == dir) ? nxt = 0 : nxt = 1;
            if(ans[nx][ny] >= ans[curnode.first][curnode.second] + nxt){
                q.push(make_pair(make_pair(nx,ny), dir));
                ans[nx][ny] = ans[curnode.first][curnode.second]+nxt;
            }
        }
    }
  
    cout<<ans[C[1].first][C[1].second];

}